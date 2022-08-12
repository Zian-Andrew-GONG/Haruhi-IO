#include "Haruhi-timer.h"
#include "timer-utils.h"
#include <memory>
using namespace Haruhi;

void Timer::init(TimerOpts opts) {
  this->m_interval = opts.interval;
  this->m_timeout = opts.interval + utils::timer::getCurrentTime();
  this->once = opts.once;
  this->m_timer_cb = opts.cb;
}

bool Timer::callback() {
  this->m_timer_cb();
  return this->once;
}

std::string Timer::type() const { return "TIMER"; }

int64_t Timer::get_timeout() const { return this->m_timeout; }

void Timer::cal_timeout() {
  this->m_timeout = this->m_interval + utils::timer::getCurrentTime();
}

