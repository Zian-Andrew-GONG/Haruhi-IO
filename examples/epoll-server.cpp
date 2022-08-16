#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include "Haruhi.h"
 
#define BUF_SIZE 100
#define EPOLL_SIZE 50
 
int main(int argc, char *argv[])
{
    int serv_sock, clnt_sock;
    struct sockaddr_in serv_adr, clnt_adr;
    socklen_t adr_sz;
    int str_len, i;
    char buf[BUF_SIZE];
 
    struct epoll_event *ep_events;
    struct epoll_event event;
    int epfd, event_cnt;
 
    if (argc != 2) {
        printf("Usage : %s <port>\n", argv[0]);
        exit(1);
    }
 
    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_adr.sin_port = htons(atoi(argv[1]));
 
    if (bind(serv_sock, (struct sockaddr *)&serv_adr, sizeof(serv_adr)) == -1)
        puts("bind() error");
    if (listen(serv_sock, 5) == -1)
        puts("listen() error");

    Haruhi::Loop loop;

    Haruhi::EpollOpts opts = {
      .fd = serv_sock,
      .events = EPOLLIN,
      .cb = [&](){ 
        puts("server callback");
        adr_sz = sizeof(clnt_adr);
        clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_adr, &adr_sz);
        Haruhi::EpollOpts opts_clnt = {
            .fd = clnt_sock,
            .events = EPOLLOUT,
            .cb = [&](){
                puts("client callback");
                char str[] = "hello";
                write(clnt_sock, str, sizeof(str) - 1);
                close(clnt_sock);
            }
        };
        Haruhi::Epoll epoll_ev_clnt;
        epoll_ev_clnt.init(opts_clnt);
        loop.add_event(epoll_ev_clnt);
      } 
    }; /* opts.once = true; */
    Haruhi::Epoll epoll_ev;
    epoll_ev.init(opts);

    loop.add_event(epoll_ev);
    loop.loop_start();

    close(serv_sock);
    // close(epfd);
    return 0;
}