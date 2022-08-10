#include <sys/time.h>
#include <chrono>
#pragma once

namespace Haruhi {
  
int64_t getCurrentTime() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

}
