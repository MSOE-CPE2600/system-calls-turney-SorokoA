/*************************************
* Filename: info.c
* Description: prints information about the 
* computer
* Author: Aiden Soroko
* Date: 11/2/2025
* To run: gcc -o info info.c
****************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/utsname.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main(int argc, char* argv[])
{
    //prints out current time of day in nanoseconds
    struct timespec ts;
    if (clock_gettime(CLOCK_REALTIME,&ts) == -1){
        perror("gettime");
        exit(1);
    }
    struct tm *timelocal = localtime(&ts.tv_sec);
    long int timens = ((timelocal->tm_hour) * 3600000000000) + ((timelocal->tm_min) * 60000000000) 
            + ((timelocal->tm_sec) * 1000000000);
    printf("Time in ns: %ld\n",timens);
    struct utsname systeminfo;
    if (uname(&systeminfo) == -1){
        perror("uname");
        exit(1);
    }
    printf("System network name: %s\nOperating systems name: %s\nOperating system release: %s\nOperating system version: %s\nHardware Name: %s\n"
        ,systeminfo.nodename,systeminfo.sysname,systeminfo.release,systeminfo.version,systeminfo.machine);
    printf("Number of processors: %d\n",get_nprocs());
    printf("Total amount of space: %ld\n",sysconf(_SC_PHYS_PAGES)*sysconf(_SC_PAGESIZE));
    printf("Amount of free space: %ld\n",sysconf(_SC_AVPHYS_PAGES)*sysconf(_SC_PAGESIZE));
    return 0;
}