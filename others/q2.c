#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(){
    char msg[100];
    int fd;
    int n;
    fd = open("f1.txt", O_CREAT | O_WRONLY | O_TRUNC, 0700);
    printf("Enter msg : ");
    fgets(msg, 100, stdin);
    write(fd, msg, strlen(msg));
    close(fd);
    fd = open("f1.txt ", O_RDONLY, 0700);
    n = read(fd,msg,strlen(msg));
    // n = strlen(msg);
    printf("ur msg : %s \n", msg );
    printf("characters %d \n", n);
    close(fd);
}