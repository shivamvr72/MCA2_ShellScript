#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
int main(){
    char buff[100];
    int fd ,n;
    fd  = open("text1.txt", O_CREAT| O_WRONLY| O_TRUNC, 06444);
    fgets(buff, 30, stdin);
    write(fd, buff, strlen(buff));
    close(fd);

    printf("your write in file: %s\n",buff);

    //for printing no of charcter in file 
    fd = open("text1.txt", O_RDONLY);
    n = read(fd, buff, strlen(buff));
    printf("characters in file : %d\n", n);
    close(fd);



}