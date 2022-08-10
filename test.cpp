#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include "include/haruhi-utils.h"

int main(int argc, char *argv[])
{
    // struct timeval time;
 
    // /* 获取时间，理论到us */
    // gettimeofday(&time, NULL);
    // printf("s: %ld, ms: %ld\n", time.tv_sec, (time.tv_sec*1000 + time.tv_usec/1000));
 
    // sleep(3);  //延时
 
    // /* 重新获取 */
    // gettimeofday(&time, NULL);
    // printf("s: %ld, ms: %ld\n", time.tv_sec, (time.tv_sec*1000 + time.tv_usec/1000));
 
 
    // exit(0);
    while (1)
    {
      Haruhi::getCurrentTime();
    }
    
    Haruhi::getCurrentTime();
    sleep(3);  //延时
    Haruhi::getCurrentTime();
}

