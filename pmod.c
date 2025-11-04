/*************************************
* Filename: pmod.c
* Description: Alters a process
* Author: Aiden Soroko
* Date: 11/2/2025
* To run: gcc -o pmod pmod.c
****************************************/

#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char* argv[])
{
    nice(10);
    struct timespec ts;
    ts.tv_sec = 1;
    ts.tv_nsec = 837272638;
    nanosleep(&ts,NULL);
    printf("Bye Bye!\n");
    return 0;
}