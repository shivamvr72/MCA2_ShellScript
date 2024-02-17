#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int fd[2],n;
    char buf[100];

    pipe(fd);
    
    pid_t pid;
    pid = fork();
    if(pid<0){
        printf("failed\n");
        exit(1);
    }else if(pid == 0){
        close(fd[0]);
        write(fd[1], "shivam rana", 11);
        close(fd[1]);

    }else{
        close(fd[1]);
        n = read(fd[0], buf, 100);
        write(STDOUT_FILENO, buf, n);
        printf("\n");
        // printf("%s" , buf);
        close(fd[0]);
    }
    
    return 0;
}