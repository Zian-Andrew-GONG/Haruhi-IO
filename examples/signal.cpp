#include "Haruhi.h"

int main() {
  Haruhi::Signal signal_ev;
  signal_ev.init({
    .sig = SIGINT,
    .cb = [](){
      puts("signal callback");
    }
  });
  Haruhi::Loop loop;
  loop.add_event(signal_ev);
  // alarm(2);
  loop.loop_start();
}