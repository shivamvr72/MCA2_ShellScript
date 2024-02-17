#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    int n = 5;
    pid_t pid;
    pid = fork();
    int fact =1;
    if(pid < 0){
        printf("Fork Failed\n");
        return 1;
    }else if(pid > 0){
        printf("parent process...\nsleep 3sec \n");
        sleep(3);
        printf("in parent fact = %d\n", fact );
    }else if(pid == 0){
        printf("child process..\n");
        printf("calculating fact...\n");
        for(int i=2; i<=n; i++){
            fact *= i;
        }
        printf("fact = %d\n", fact );
    }

    return 0;
}
