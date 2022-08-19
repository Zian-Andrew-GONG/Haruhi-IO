#include "epoll-wrapper.h"
#include "common.h"
using namespace Haruhi;

std::shared_ptr<EpollWrapper> EpollWrapper::epoll_ptr = nullptr;

int EpollWrapper::epoll_add(int fd, uint32_t events) {
  struct epoll_event event_struct;
  event_struct.events = events;
  event_struct.data.fd = fd;
  int ret = epoll_ctl(m_epoll_fd, EPOLL_CTL_ADD, fd, &event_struct);
  if(ret < 0) printf("epoll_ctl(): %s\n", strerror(errno));
  return ret;
}
int EpollWrapper::epoll_del(int fd, uint32_t events) {
  struct epoll_event event_struct;
  event_struct.events = events;
  event_struct.data.fd = fd;
  int ret = epoll_ctl(m_epoll_fd, EPOLL_CTL_DEL, fd, &event_struct);
  if(ret < 0) printf("epoll_ctl(): %s\n", strerror(errno));
  return ret;
}
int EpollWrapper::epoll_mod(int fd, uint32_t events) {
  struct epoll_event event_struct;
  event_struct.events = events;
  event_struct.data.fd = fd;
  int ret = epoll_ctl(m_epoll_fd, EPOLL_CTL_MOD, fd, &event_struct);
  if(ret < 0) printf("epoll_ctl(): %s\n", strerror(errno));
  return ret;
}

struct epoll_event* EpollWrapper::get_epoll_out_events() { return m_epoll_out_events; }

int& EpollWrapper::get_ref_epoll_fd() { return this->m_epoll_fd; }

int EpollWrapper::wait(int timeout) {
  int ret;
  do {
    ret = epoll_wait(m_epoll_fd, m_epoll_out_events, 2048, timeout);
    if(ret < 0) printf("epoll_wait(): %s\n", strerror(errno));
  } while (ret < 0 && errno == EINTR);
  return ret;
}