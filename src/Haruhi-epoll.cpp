#include "Haruhi-epoll.h"

using namespace Haruhi;

void Epoll::init(EpollOpts opts) {
  this->once = opts.once;
  this->m_cb = opts.cb;
  this->m_fd = opts.fd;
  this->m_events = opts.events;
  this->epoll_wrapper = EpollWrapper::getEpollWrapper();
  this->epoll_wrapper->epoll_add(this->m_fd, this->m_events);
}

bool Epoll::callback() {
  if(this->m_cb)
    this->m_cb();
  else puts("callback error");
  return once;
}

std::string Epoll::type() const { return "EPOLL"; }

int Epoll::get_fd() const { return m_fd; }

uint32_t Epoll::get_events() const { return m_events; }