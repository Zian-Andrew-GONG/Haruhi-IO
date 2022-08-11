#include "Haruhi-timer.h"
#include "timer-utils.h"
#include <memory>
using namespace Haruhi;

void Timer::init(TimerOps ops) {
  this->m_interval = ops.interval;
  this->m_timeout = ops.interval + utils::timer::getCurrentTime();
  this->once = ops.once;
  this->m_timer_cb = ops.cb;
}

bool Timer::callback() {
  this->m_timer_cb();
  return once;
}

std::string Timer::type() const { return "Timer"; }

int64_t Timer::get_timeout() const { return this->m_timeout; }

void Timer::cal_timeout() {
  this->m_timeout = this->m_interval + utils::timer::getCurrentTime();
}
