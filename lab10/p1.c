#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    int oldfd , newfd, redfd;
    char buf[100];
    oldfd = open("t1.txt", O_RDWR);
    printf("oldfd = %d \n", oldfd);
    newfd = dup(oldfd);
    printf("newfd = %d \n", newfd);

    read(newfd, buf, 33);
    printf("%s\n", buf);
    return 0;
}