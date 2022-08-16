#include "Haruhi-signal.h"

using namespace Haruhi;

void Signal::init(SignalOpts opts) {
  
}

bool Signal::callback() {
  this->m_signal_cb();
  return this->once;
}

std::string Signal::type() const {
  return "SIGNAL";
}
