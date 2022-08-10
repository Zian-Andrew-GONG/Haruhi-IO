#include "haruhi.h"
#include <iostream>

int main() {
  Haruhi::Loop loop;
  Haruhi::Timer timer, timer_1, timer_2;
  Haruhi::TimerOps timer_ops = {
    .interval = 3000,
    .cb = [](){std::cout << "timer event ..." << std::endl; }
  };
  timer.init(timer_ops);
  loop.add_event(timer);

  timer_ops.interval = 5000;
  timer_ops.cb = [](){std::cout << "timer_1 event ..." << std::endl; };
  timer_1.init(timer_ops);
  loop.add_event(timer_1);

  timer_ops.interval = 1000;
  timer_ops.cb = [](){std::cout << "timer_2 event ..." << std::endl; };
  timer_2.init(timer_ops);
  loop.add_event(timer_2);
  
  loop.loop_start();

  return 0;
}