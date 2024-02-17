#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int fd, fd1,n;
    char buf[100];
    pid_t pid;
    pid = fork();
    switch(pid){
        case -1: printf("fork error!\n");break;
        case 0:
            printf("child creating file...\n");
            fd = open("test1.txt", O_RDONLY);
            fd1 = open("test9.txt", O_CREAT| O_WRONLY| O_TRUNC, 0644);  
            // fgets(buf, 20, stdin);
            n = read(fd, buf, 40);
            write(fd1, buf, n);
            close(fd1);
            // break;
        default:
            printf("parent process printing\n");
            fd1 = open("test9.txt", O_RDONLY);
            n = read(fd1, buf, strlen(buf));
            printf("%s\n", buf);
    }
    return 0;
}