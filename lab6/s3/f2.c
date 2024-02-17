#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(){
    int fd, fd2, offset, n;
    char buf[100], c;
    fd = open("text1.txt", O_RDONLY);
    fd2 = open("text2.txt", O_CREAT | O_WRONLY | O_TRUNC, 0700);

    if(fd < 0){
        printf("Fd error\n");
    }

    offset = lseek(fd, 21, SEEK_SET);
    while(offset >= 0){
        read(fd, &c, 1);
        write(fd2, &c, 1);
        lseek(fd, -2, SEEK_CUR);
        offset--;
    }

}