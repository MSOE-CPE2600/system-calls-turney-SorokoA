/*************************************
* Filename: finfo.c
* Description: prints information about a file
* Author: Aiden Soroko
* Date: 11/2/2025
* To run: gcc -o finfo finfo.c
****************************************/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <sys/stat.h>

int main(int argc, char* argv[])
{
    if (argc > 1){
        int fd = open(argv[1], O_RDONLY, 0);
        struct stat info;
        fstat(fd,&info);
        int mode = info.st_mode;
        printf("File type: ");
        switch(mode & S_IFMT){
            case S_IFREG:
                printf("Regular File\n");
                break;
            case S_IFDIR:
                printf("Directory\n");
                break;
            case S_IFLNK:
                printf("Symbolic Link\n");
                break;
            case S_IFCHR:
                printf("Character Device\n");
                break;
            case S_IFBLK:
                printf("Block Device\n");
                break;
            case S_IFIFO:
                printf("First In First Out\n");
                break;
            case S_IFSOCK:
                printf("Socket\n");
                break;
            default:
                perror("unknown file\n");
                exit(1);
        }
        printf("Permissions: ");
        if (S_ISDIR(mode)){
            printf("d");
        } else {
            printf("-");
        }
        if (mode & S_IRUSR){
            printf("r");
        } else {
            printf("-");
        }
        if (mode & S_IWUSR){
            printf("w");
        } else {
            printf("-");
        }
        if (mode & S_IXUSR){
            printf("x");
        } else {
            printf("-");
        }
        if (mode & S_IRGRP){
            printf("r");
        } else {
            printf("-");
        }
        if (mode & S_IWGRP){
            printf("w");
        } else {
            printf("-");
        }
        if (mode & S_IXGRP){
            printf("x");
        } else {
            printf("-");
        }
        if (mode & S_IROTH){
            printf("r");
        } else {
            printf("-");
        }
        if (mode & S_IWOTH){
            printf("w");
        } else {
            printf("-");
        }
        if (mode & S_IXOTH){
            printf("x\n");
        } else {
            printf("-\n");
        }
        printf("Size in Bytes: %ld\n",info.st_size);
        time_t time = info.st_mtime;
        struct tm tm;
        localtime_r(&time,&tm);
        char output[80];
        strftime(output, sizeof(output), "%c", &tm);
        printf("Last modified: %s\n",output);

    } else {
        perror("no file\n");
        exit(1);
    }    

    return 0;
}