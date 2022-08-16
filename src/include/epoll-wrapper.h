#include <sys/epoll.h>
#include <memory>
#include <set>
#include "common.h"
#pragma once

namespace Haruhi {

/* class EpollFd only operates the kernel event list */
class EpollWrapper {
  public:
    static std::shared_ptr<EpollWrapper> getEpollWrapper(int size = 2048) {
      if(epoll_ptr == nullptr) {
        epoll_ptr = std::shared_ptr<EpollWrapper>(new EpollWrapper(size));
      } 
      return epoll_ptr; 
    }
    int epoll_add(int fd, uint32_t events);
    int epoll_del(int fd, uint32_t events);
    int epoll_mod(int fd, uint32_t events);
    struct epoll_event* get_epoll_out_events();
    int& get_ref_epoll_fd();
    int wait(int timeout);
  private:
    EpollWrapper(int size) {
      m_epoll_fd = epoll_create(size);
      if(m_epoll_fd < 0) printf("epoll_create(): %s\n", strerror(errno));
      m_epoll_out_events = (struct epoll_event*)malloc(sizeof(struct epoll_event) * size);
    }
    static std::shared_ptr<EpollWrapper> epoll_ptr;
    int m_epoll_fd;
    struct epoll_event* m_epoll_out_events;
};
}