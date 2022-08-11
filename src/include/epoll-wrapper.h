#include "Haruhi-event.h"
#include <functional>

#pragma once

namespace Haruhi {

using epoll_cb = std::function<void()>;

struct EpollOps: public EventOps
{
  epoll_cb cb;
};

class Epoll: public Event {
  public:
    
  private:

};

}