#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
    int n, fd[2], *arr1, *buf;

    printf("Enter size of an array: ");
    scanf("%d", &n);

    arr1 = (int *) malloc(sizeof(int)*n);
    buf = (int *) malloc(sizeof(int)*n);

    pipe(fd);

    pid_t pid;
    pid = fork();
    if(pid < 0){
        printf("fork error\n");
        exit(1);
    }else if(pid == 0){
        printf("child wrinting in pipe...\n");
        close(fd[0]);
        for(int i=0; i<n; i++){
            *(arr1+i) = i;
        }
        write(fd[1], arr1, sizeof(int)*n);
        close(fd[1]);
    }else{
        sleep(1);
        printf("parent process reading through pipe..\n");
        close(fd[1]);
        int x = read(fd[0], buf, sizeof(int)*10);
        for(int i=0; i<n; i++){
            printf("%d ", *(buf+i));
        }
        printf("\n");
        close(fd[0]);
    }
    return 0;
}