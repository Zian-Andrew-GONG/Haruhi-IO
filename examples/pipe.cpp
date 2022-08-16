#include "Haruhi.h"
#include <stdio.h>
#include <unistd.h>

#define BUF_SIZE 30

int main(int argc, char* argv[]) {
  int fds[2];
  char str[] = "Who are you?";
  char buf[BUF_SIZE];
  pid_t pid;
  pipe(fds);  // 调用pipe函数创建管道，fds数组中保存用于I/O的文件描述符；
              // 父进程此时获取了对应于出入口的文件描述符。
  Haruhi::Loop loop;
  Haruhi::Epoll epoll_ev;
  Haruhi::EpollOpts opts = {
    .fd = fds[0],
    .events = EPOLLIN,
    .cb = [&](){
      read(fds[0], buf, BUF_SIZE);
      puts(buf);
    }
  }; opts.once = true;
  epoll_ev.init(opts);
  loop.add_event(epoll_ev);


  pid = fork();  // 接着调用fork函数。子进程同时拥有两个文件描述符。
  if(pid == 0) {  // 子进程 写
    write(fds[1], str, sizeof(str));
  }
  else {  // 父进程 读
    loop.loop_start();
  }
  return 0;
}