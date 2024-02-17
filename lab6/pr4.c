#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    int fd, fd2, n, offset;
    char buf[100], cc;

    fd = open("test1.txt", O_RDONLY);
    fd2 = open("test8.txt", O_CREAT| O_WRONLY| O_TRUNC, 0700);

    if(fd<0){
        printf("open error\n");
    } 

    offset = lseek(fd, 14, SEEK_SET);
    while(offset>0){
        read(fd, &cc, 1);
        write(fd2, &cc, 1);
        lseek(fd, -2, SEEK_CUR);
        offset--;
    }

}