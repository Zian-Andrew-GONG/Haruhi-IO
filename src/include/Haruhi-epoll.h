#include "Haruhi-event.h"
#include "epoll-wrapper.h"
#include <memory>
#include <functional>

namespace Haruhi {

using epoll_cb = std::function<void()>;

struct EpollOpts: public EventOpts
{
  int fd;
  uint32_t events;
  epoll_cb cb;
};


class Epoll: public Event {
  public:
    void init(EpollOpts opts);
    virtual bool callback();
    virtual std::string type() const;
    int get_fd() const;
    uint32_t get_events() const;
  private:
    epoll_cb m_cb;
    bool once;
    int m_fd;
    uint32_t m_events;
    std::shared_ptr<EpollWrapper> epoll_wrapper;
};

}