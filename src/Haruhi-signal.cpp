#include "Haruhi-signal.h"
#include "common.h"
#include <signal.h>
// int sigaction(int sig, const struct sigaction* act, struct sigaction* oldact);
using namespace Haruhi;

void sig_handler(int sig){
  /* write into peer 0 */

}

void Signal::init(SignalOpts opts) {
  this->once = opts.once;
  this->m_signal_cb = opts.cb;
  this->m_sig = opts.sig;
  struct sigaction sa;
  sa.sa_handler = sig_handler;  // 指定信号处理函数
  sigaction(m_sig, &sa, NULL);
  /* create pipe */
  char str[] = "notify the peer";
  int fds[2];
  pipe(fds);
  m_epoll_ev.init({.fd = fds[0],
                  .events = EPOLLIN,
                  .cb = m_signal_cb
                  });
}

bool Signal::callback() {
  this->m_signal_cb();
  return this->once;
}

std::string Signal::type() const {
  return "SIGNAL";
}

int Signal::get_read_fd() const {
  return m_read_fd;
}
int Signal::get_write_fd() const {
  return m_write_fd;
}
signal_cb Signal::get_cb() const {
  return m_signal_cb;
}
Epoll& Signal::get_epoll_ev() {
  return m_epoll_ev;
}