/*************************************
* Filename: pinfo.c
* Description: retrieves process info
* Author: Aiden Soroko
* Date: 11/2/2025
* To run: gcc -o pinfo pinfo.c
****************************************/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sched.h>
#include <errno.h>

int main(int argc, char* argv[])
{
    pid_t pid;
    if (argc == 1){//no arguments specified
        pid = getpid();
    } else if (argc == 2){
        pid = atoi(argv[1]);
    } else {
        perror("process info");
        exit(1);
    }
    errno = 0;
    int priority = getpriority(PRIO_PROCESS,pid);
    if (priority == -1 && errno != 0){
        perror("invalid pid number\n");
        exit(1);
    }
    
    printf("%d\n",priority);
    int policy = sched_getscheduler(pid);
    if(policy == -1){
        perror("sched_getscheduler\n");
        exit(1);
    }
    switch(policy){
        case SCHED_OTHER:
            printf("Policy: SCHED_OTHER\n");
            break;
        case SCHED_BATCH:
            printf("Policy: SCHED_BATCH\n");
            break;
        case SCHED_IDLE:
            printf("Policy: SCHED_IDLE\n");
            break;
        case SCHED_FIFO:
            printf("Policy: SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("Policy: SCHED_RR\n");
            break;
        default:
            printf("unknown policy\n");
            break;
    }

    return 0;
}