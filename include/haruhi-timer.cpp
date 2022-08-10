#include "haruhi-timer.h"
#include "haruhi-utils.h"
#include <memory>
using namespace Haruhi;

void Timer::init(std::shared_ptr<TimerOps> ops) {
  this->m_interval = ops->interval;
  this->m_timeout = ops->interval + getCurrentTime();
  this->once = ops->once;
  this->m_timer_cb = ops->cb;
}

bool Timer::callback() {
  this->m_timer_cb();
  return once;
}

int64_t Timer::get_timeout() const { return this->m_timeout; }

void Timer::cal_timeout() {
  this->m_timeout = this->m_interval + getCurrentTime();
}

