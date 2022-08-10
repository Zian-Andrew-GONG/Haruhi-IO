/**
 * @file timer.h
 * @author GongZian (https://github.com/Zian-Andrew-GONG)
 * @brief This is the header file which defines classes 
 *        and functions related to timer events.
 * @version 0.1
 * @date 2022-08-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "haruhi-event.h"
#include <functional>

#pragma once

namespace Haruhi {

using timer_cb = std::function<void()>;

struct TimerOps: public EventOps
{
  int64_t interval;
  timer_cb cb;
};


class Timer: public Event {
  public:
    void init(std::shared_ptr<TimerOps> ops);
    virtual bool callback() override;
    virtual std::string type() const override { 
      return "Timer"; }
    int64_t get_timeout() const;
    void cal_timeout();
  private:
    int64_t m_timeout;
    int64_t m_interval;
    timer_cb m_timer_cb;
    bool once;
};

}
