#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
    int fd1, fd2, fd3, n, i;
    char buf[100];
    fd1 = open("test3.txt", O_RDONLY);
    fd2 = open("test4.txt", O_RDONLY);
    fd3 = open("merge.txt", O_CREAT | O_WRONLY | O_APPEND, 0600);
 
    int  s=0;
    printf("No of character to read from each file: ");
    scanf("%d", &s);

    n = read(fd1, buf, s);
    write(fd3, buf, n);
    close(fd1);


    n = read(fd2, buf, s);
    write(fd3, buf, n);
    close(fd2);
    close(fd3);
    printf("\n");

    return 0;
}
