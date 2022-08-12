#include "epoll-wrapper.h"
#include <sys/epoll.h>

using namespace Haruhi;

std::shared_ptr<EpollWrapper> EpollWrapper::epoll_ptr = nullptr;

int EpollWrapper::epoll_add(int fd, uint32_t events) {
  struct epoll_event event_struct;
  event_struct.events = events;
  return epoll_ctl(m_epoll_fd, EPOLL_CTL_ADD, fd, &event_struct);
}
int EpollWrapper::epoll_del(int fd, uint32_t events) {
  struct epoll_event event_struct;
  event_struct.events = events;
  return epoll_ctl(m_epoll_fd, EPOLL_CTL_DEL, fd, &event_struct);
}
int EpollWrapper::epoll_mod(int fd, uint32_t events) {
  struct epoll_event event_struct;
  event_struct.events = events;
  return epoll_ctl(m_epoll_fd, EPOLL_CTL_MOD, fd, &event_struct);
}

struct epoll_event* EpollWrapper::get_epoll_out_events() { return m_epoll_out_events; }

int EpollWrapper::wait(int timeout) {
  int ret = epoll_wait(m_epoll_fd, m_epoll_out_events, 2048, timeout);
  return ret;
}