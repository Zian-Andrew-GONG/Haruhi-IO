#include "Haruhi-epoll.h"

void Epoll::init(EpollOpts opts) {
  this->once = opts.once;
  this->m_cb = opts.cb;
  this->m_fd = opts.fd;
  this->m_events = opts.events;
  this->epoll_wrapper = EpollWrapper::getEpollWrapper();
  this->epoll_wrapper->epoll_add(this->m_fd, this->m_events);
}

bool Epoll::callback() {
  this->m_cb();
  return once;
}

std::string Epoll::type() const { return "EPOLL"; }

int Epoll::get_fd() const { return m_fd; }

uint32_t Epoll::get_events() const { return m_events; }