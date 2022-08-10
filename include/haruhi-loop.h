/**
 * @file loop.h
 * @author GongZian (https://github.com/Zian-Andrew-GONG)
 * @brief This is the header file which defines classes 
 *        and functions related to the event loop 
 * @version 0.1
 * @date 2022-08-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "haruhi-event.h"
#include "haruhi-timer.h"

#include <deque>
#include <queue>
#include <vector>
#include <memory>
#include <functional>

#pragma once

namespace Haruhi {

class Loop {
  public:
    void loop_start();
    // void loop_stop();
    template <typename T>
    void add_event(const T& event) {
      if(event.type() == "Timer") {
        auto timer = std::make_shared<Timer>(event);
        this->timer_que.push_back(timer);
        push_heap(this->timer_que.begin(), this->timer_que.end(), Compare());
      } else if(event.type() == "Signal") {

      } else if(event.type() == "Demux") {
      
      }
    }
    template <typename T>
    bool remove_event(const T& event);
  private:
    class Compare {
      public:
        bool operator() (const std::shared_ptr<Timer>& a, const std::shared_ptr<Timer>& b) {
          if(a->get_timeout() < b->get_timeout()) return true;
          return false;
        }
    };
    std::vector<std::shared_ptr<Timer>> timer_que;
    std::queue<std::shared_ptr<Event>> Signal_que;
    std::queue<std::shared_ptr<Event>> Demux_que;
    int64_t current_time;
};

}
