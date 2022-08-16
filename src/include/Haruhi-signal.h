#include "Haruhi.h"

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

  private:
    bool once;
    signal_cb m_signal_cb;

};

}