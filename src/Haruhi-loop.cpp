#include "Haruhi-loop.h"
#include "loop-utils.h"
// #include <iostream>

using namespace Haruhi;

void Loop::loop_start() {
  while(1) {
    if(this->timer_que.empty() && this->signal_que.empty() 
       && this->demux_que.empty()) break;
    /* stop the loop immediately */
    if(this->stop_flag) break;

    /* update current time */
    this->current_time = utils::loop::getCurrentTime();
    /* get the reference of the timer heap */
    auto& timer_heap = this->timer_que;
    /* calculate the timewait value */
    make_heap(timer_heap.begin(), timer_heap.end(), Compare());
    auto timewait = timer_heap[0]->get_timeout() - this->current_time;
    /* epoll's timeout = timewait */
    /*  */

    /* process the timer event */
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
}

void Loop::loop_stop() {
  this->stop_flag = true;
}

// template <typename T>
// void Loop::add_event(const T& event) {
//   if(event.type() == "Timer") {
//     auto& timer = std::make_shared<Timer>(event);
//     this->timer_que.push_back(timer);
//     push_heap(this->timer_que.begin(), this->timer_que.end(), Compare());
//   } else if(event.type() == "Signal") {

//   } else if(event.type() == "Demux") {

//   }
// }

// template <typename T>
// bool Loop::remove_event(const T& event) {
//   if(event.type() == "Timer") {
//     auto& timer_heap = this->timer_que;
//     auto timer = std::make_shared<Timer>(event);
//     for(auto iter = timer_heap.begin(); iter != timer_heap.end(); iter++) {
//       if(*iter == timer) {
//         timer_heap.erase(iter);
//       }
//     }
//   }
// }