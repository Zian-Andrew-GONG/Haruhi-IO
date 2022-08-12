#include "Haruhi.h"
#include <iostream>

int main() {
  Haruhi::Loop loop;
  Haruhi::Timer timer, timer_1, timer_2;
  Haruhi::TimerOpts timer_opts = {
    .interval = 2000,
    .cb = [](){std::cout << "timer event ..." << std::endl; }
  };
  timer.init(timer_opts);
  loop.add_event<Timer>(timer);

  timer_opts.interval = 5000;
  timer_opts.cb = [&loop](){
    loop.loop_stop();
    std::cout << "timer_1 event ..." << std::endl; };
  timer_1.init(timer_opts);
  loop.add_event<Timer>(timer_1);

  timer_opts.interval = 1000;
  timer_opts.cb = [](){std::cout << "timer_2 event ..." << std::endl; };
  timer_2.init(timer_opts);
  loop.add_event<Timer>(timer_2);
  
  loop.loop_start();
  return 0;
}