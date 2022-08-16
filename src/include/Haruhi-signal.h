#include "Haruhi-event.h"
#include "Haruhi-epoll.h"
#include <functional>

namespace Haruhi {

using signal_cb = std::function<void()>;

struct SignalOpts: public EventOpts
{
  int sig;
  signal_cb cb;
};

class Signal: public Event {
  public:
    void init(SignalOpts opts);
    virtual bool callback() override;
    virtual std::string type() const override;
    int get_read_fd() const;
    int get_write_fd() const;
    signal_cb get_cb() const;
    Epoll& get_epoll_ev();
  private:
    bool once;
    signal_cb m_signal_cb;
    int m_sig;
    int m_read_fd;
    int m_write_fd;
    Epoll m_epoll_ev;
};

}