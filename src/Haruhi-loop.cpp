#include "Haruhi-loop.h"
#include "loop-utils.h"
#include "common.h"
#include <set>
using namespace Haruhi;

void Loop::add_event(const Timer& event) {
  auto timer = std::make_shared<Timer>(event);
  this->timer_que.push_back(timer);
  push_heap(this->timer_que.begin(), this->timer_que.end(), Compare());
}
void Loop::add_event(const Epoll& event) {
  auto epoll = std::make_shared<Epoll>(event);
  if(epoll == nullptr) puts("add_event nullptr");
  this->epoll_que.insert(epoll);
  epoll_map[event.get_fd()] = epoll;
}
void Loop::add_event(const Signal& event) {
  auto signal = std::make_shared<Signal>(event);
  if(signal == nullptr) puts("add_event nullptr");
  this->signal_que.insert(signal);
  auto& epoll_ev = signal->get_epoll_ev();
  this->add_event(epoll_ev);
}

bool Loop::remove_event(const Timer& event) {
  auto& timer_heap = this->timer_que;
  auto timer = std::make_shared<Timer>(event);
  for(auto iter = timer_heap.begin(); iter != timer_heap.end(); iter++) {
    if(*iter == timer) {
      timer_heap.erase(iter);
      return true;
    }
  }
  return false;
}

bool Loop::remove_event(const Epoll& event) {
  auto& set = this->epoll_que;
  auto epoll_ev = std::make_shared<Epoll>(event);
  set.erase(epoll_ev);
  this->epoll_map.erase(epoll_ev->get_fd());
  return true;
}

bool Loop::remove_event(const Signal& event) {
  auto& set = this->signal_que;
  auto signal = std::make_shared<Signal>(event);
  set.erase(signal);
  this->remove_event(signal->get_epoll_ev());
  return true;
}

void Loop::loop_start() {
  puts("loop started ...");
  while(1) {
    if(this->timer_que.empty() && this->signal_que.empty() 
       && this->epoll_que.empty()) break;
       std::cout << "timer_que.size(): " << timer_que.size() 
                << "\nsignal_que.size(): " << signal_que.size()
                << "\nepoll_que.size(): " << epoll_que.size()
                << "\nepoll_map.size(): " << epoll_map.size() << std::endl;
    /* stop the loop immediately */
    if(this->stop_flag) break;
    /* update current time */
    this->current_time = utils::loop::getCurrentTime();
    /* get the reference of the timer heap */
    auto& timer_heap = this->timer_que;
    /* calculate the timewait value */
    long timewait = 0;
    make_heap(timer_heap.begin(), timer_heap.end(), Compare());
    if(!timer_heap.empty())
      timewait = timer_heap[0]->get_timeout() - this->current_time;
    if(timewait < 0) timewait = 0;
    /* epoll's timeout = timewait */
    auto epoll_wrapper = EpollWrapper::getEpollWrapper();
    // std::cout << "timewait = " << timewait << std::endl;
    int ret = epoll_wrapper->wait(-1);
    if(ret < 0) break;
    auto epoll_out_events = epoll_wrapper->get_epoll_out_events();
    for(int i = 0; i < ret; ++i) {
      auto active_fd = epoll_out_events[i].data.fd;
      std::cout << "active_fd = " << active_fd << std::endl;
      auto epoll = this->epoll_map[active_fd];
      if(epoll == nullptr) puts("nullptr");
      bool once = epoll->callback();
      if(once) {
        this->epoll_que.erase(epoll);
        this->epoll_map.erase(active_fd);
        epoll_wrapper->epoll_del(epoll->get_fd(), epoll->get_events());
      }
    }
    

    /* process the timer event */
    if(timer_heap.empty()) continue;
    std::shared_ptr<Haruhi::Timer> timer_node = timer_heap[0];
    if(timer_node->get_timeout() < this->current_time) {
      auto once = timer_node->callback();
      pop_heap(timer_heap.begin(), timer_heap.end(), Compare());
      timer_heap.pop_back();
      if(!once) {
        timer_node->cal_timeout();
        timer_heap.push_back(timer_node);
        push_heap(timer_heap.begin(), timer_heap.end(), Compare());
      }
    }

  }
  auto epoll_wrapper = EpollWrapper::getEpollWrapper();
  close(epoll_wrapper->get_ref_epoll_fd());
}

void Loop::loop_stop() {
  this->stop_flag = true;
}