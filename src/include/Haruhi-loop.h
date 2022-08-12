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

#include "Haruhi-event.h"
#include "Haruhi-timer.h"
#include "Haruhi-epoll.h"

#include <queue>
#include <list>
#include <vector>
#include <memory>
#include <functional>
#include <unordered_map>

#pragma once

namespace Haruhi {

class Loop {
  public:
    void loop_start();
    void loop_stop();
    template <class T>
    void add_event(const T& event) {
      if(event.type() == "TIMER") {
        auto timer = std::make_shared<T>(event);
        this->timer_que.push_back(timer);
        push_heap(this->timer_que.begin(), this->timer_que.end(), Compare());
      } else if(event.type() == "SIGNAL") {
      } /* else if(event.type() == "EPOLL") {
        auto epoll = std::make_shared<T>(event);
        this->epoll_que.insert(epoll);
        epoll_map[event.get_fd()] = epoll;
      } */
    }
    template <typename T>
    bool remove_event(const T& event);
  private:
    class Compare {
      public:
        bool operator() (const std::shared_ptr<Timer>& a, const std::shared_ptr<Timer>& b) {
          if(a->get_timeout() > b->get_timeout()) return true;
          return false;
        }
    };
    std::vector<std::shared_ptr<Timer>> timer_que;
    std::list<std::shared_ptr<Event>> signal_que;
    std::set<std::shared_ptr<Epoll>> epoll_que;
    std::unordered_map<int, std::shared_ptr<Epoll>> epoll_map;
    int64_t current_time;
    bool stop_flag = false;
};

}
