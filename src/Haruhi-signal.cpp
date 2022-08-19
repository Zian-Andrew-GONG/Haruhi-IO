#include "Haruhi-signal.h"
#include "common.h"
using namespace Haruhi;

static int fds[2];

int setnonblocking(int fd) {
  int old_option = fcntl(fd, F_GETFL);  // 获取文件描述符旧的状态标志
  int new_option = old_option | O_NONBLOCK;  // 设置非阻塞标志
  fcntl(fd, F_SETFL, new_option);
  return old_option;  // 返回文件描述符旧的状态标志，以便日后恢复该状态标志
}

void sig_handler(int sig){
  /* write into peer 1 */
  puts("signal handler");
  std::cout << "fds[0] = " << fds[0] << "\n"
  << "fds[1] = " << fds[1] << std::endl;
  send(fds[1], "a", 1, 0);
  // sleep(2);
  char message[30];
  recv(fds[0], message, sizeof(message) - 1, 0);
  puts(message);
}

void Signal::init(SignalOpts opts) {
  this->once = opts.once;
  this->m_signal_cb = opts.cb;
  this->m_sig = opts.sig;
  std::cout << "fds[0] = " << fds[0] << "\n"
  << "fds[1] = " << fds[1] << std::endl;
  /* create pipe */
  pipe(fds);
  setnonblocking(fds[0]);
  setnonblocking(fds[1]);
  printf("fds[0] = %d, fds[1] = %d\n", fds[0], fds[1]);
  struct sigaction sa;
  sa.sa_handler = sig_handler;  // 指定信号处理函数
  sigaction(m_sig, &sa, NULL);
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