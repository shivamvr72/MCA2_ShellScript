#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    int buf[100];
    int ibuf[100];
    int n, fd[2], no;

    printf("Enter size : ");
    scanf("%d", &no);
    for(int i=0; i<no; i++){
        printf("Enter element : ");
        scanf("%d", &ibuf[i]);
    }
    
    pipe(fd);
    
    pid_t pid;
    pid = fork();
    if(pid < 0){
        printf("fork failed\n");
    }else if(pid == 0){
        write(fd[1], ibuf, no);
        close(fd[0]);
    }else{
        for(int i=0; i<no; i++){
            read(fd[0], buf, no);
            write(STDOUT_FILENO, buf, no);
        }
        close(fd[1]);
    }

    return 0;
}