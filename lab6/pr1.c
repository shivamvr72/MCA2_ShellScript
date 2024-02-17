#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

// #include <sys/types.h>

int main(){
    char buf[100], i, n ,fd;

    fd = open("test1.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    fgets(buf, 15, stdin);
    write(fd, buf, strlen(buf));
    close(fd);

    printf("your msg : %s", buf);
    fd = open("test1.txt", O_RDONLY);
    n=read(fd, buf, strlen(buf));
    printf("%d\n", n-1);
    close(fd);
    return 0;
}
