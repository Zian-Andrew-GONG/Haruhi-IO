#include <iostream>
#include <netinet/in.h>
#include <sys/un.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "wrong input" << std::endl;
        exit(1);
    }
    struct sockaddr_in serv_addr;

    char message[30];

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));


    int client_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (client_sock == -1) {
        std::cout << "socket() error" << std::endl;
        exit(1);
    }

    if (connect(client_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
        std::cout << "connect() error" << std::endl;
        exit(1);
    }

    int strlen = recv(client_sock, message, sizeof(message) - 1, 0);
    // char str[] = "hello!";
    // int strlen = send(client_sock, str, sizeof(str) - 1, 0);
    if (strlen == -1) {
        std::cout << "read() error" << std::endl;
        exit(1);
    }

    std::cout << message << std::endl;
    close(client_sock);
    return 0;
}