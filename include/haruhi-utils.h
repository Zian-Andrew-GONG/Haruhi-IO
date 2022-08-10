#include <sys/time.h>
#pragma once

namespace Haruhi {
  
int64_t getCurrentTime() {
  struct timeval tv;
  gettimeofday(&tv, nullptr);
  return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

}
