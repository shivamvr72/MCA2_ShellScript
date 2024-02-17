#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
    int fd[2], buf[2], n1, n2;

    pipe(fd);

    int nos[2];
    printf("Enter no1 : ");
    scanf("%d", &nos[0]);
    printf("Enter no2 : ");
    scanf("%d", &nos[1]);


    pid_t pid;
    pid = fork();

    if(pid < 0){
        printf("Fork failed\n");
        exit(1);
    }else if(pid == 0){
        printf("child writes...\n");
        close(fd[0]);
        write(fd[1], nos, sizeof(int)*2);
    }else{
        printf("parent process...\n");
        close(fd[1]);
        int rn = read(fd[0], buf, sizeof(int)*2);
        int sum = buf[1]+buf[0];
        printf("sum of two number : %d \n", sum);
    }
    return 0;
}