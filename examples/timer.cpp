#include "haruhi.h"
#include <iostream>

int main() {
  Haruhi::Loop loop;
  Haruhi::Timer timer;
  Haruhi::TimerOps timer_ops = {
    .interval = 5000,
    .cb = [](){std::cout << "timer event ..." << std::endl; },
  };
  timer_ops.once = true;
  auto timer_ops_ptr = std::make_shared<Haruhi::TimerOps>(timer_ops);
  timer.init(timer_ops_ptr);
  loop.add_event(timer);
  loop.loop_start();

  return 0;
}