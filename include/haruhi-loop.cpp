#include "haruhi-loop.h"
// #include "haruhi-utils.h"

using namespace Haruhi;

void Loop::loop_start() {
  while(1) {
    /* 矫正时间 */
    // this->current_time = getCurrentTime();
    
    /* 处理 timer */
    // auto timer_node = this->timer_que.top();
    auto& timer_heap = this->timer_que;
    make_heap(timer_heap.begin(), timer_heap.end(), Compare());
    auto& timer_node = timer_heap[0];
    if(timer_node->get_timeout() >= this->current_time) {
      auto once = timer_node->callback();
      pop_heap(timer_heap.begin(), timer_heap.end(), Compare());
      timer_heap.pop_back();
      if(!once) {
        timer_node->cal_timeout();
        timer_heap.push_back(timer_node);
        push_heap(timer_heap.begin(), timer_heap.end(), Compare());
      }
    }
    /* epoll 阻塞 timewait 时间 */

  }
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