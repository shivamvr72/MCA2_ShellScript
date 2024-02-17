#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    int fd, fd2, n, offset;
    char buf[100];

    fd = open("test1.txt", O_RDONLY); 
    fd2 = open("test7.txt", O_CREAT| O_WRONLY| O_TRUNC, 0700);


    if(fd<0){
        printf("open error\n");
    }

    offset = lseek(fd, 11, SEEK_SET);
    n = read(fd, buf,50);

    write(fd2, buf, n);

    close(fd);
    close(fd2);
    return 0;
}