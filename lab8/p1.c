#include <stdio.h>
#include <unistd.h>

int main(){
    int n, fd[2];
    char buff[100];

    pipe(fd);

    printf("write through pipe to buf\n");
    write(fd[1], "hello", 5); //fd[1] = write; fd[0] = read
    printf("read from pipe\n");
    read(fd[0], buff, 100);
    printf("%s\n", buff);
    return 0;
}