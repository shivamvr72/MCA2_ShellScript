#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(){
    int fd[2], in , out;
    char *arrexe[] = {"cat", NULL};

    pipe(fd);

    switch(fork()){
        case -1 : printf("fork error\n"); exit(1); break;
        case 0: 
            //child process 
            close(fd[0]); //read close becuase will not read from pipe
            dup2(fd[1], STDOUT_FILENO); // close std out and copied to fd1 (pipe) insted of display will be write in pipe or redirected to pipe
            execlp("cat", "cat", "in.txt", NULL ); //cat executes and o/p content redirected to pipe
            close(fd[1]); 
            break;
        default:
            //parent process
            close(fd[1]); //write close because will not write into pipe
            dup2(fd[0], STDIN_FILENO); // close stdin so will not take input/read from keyboard insted read from pipe thats why copied to fd0(pipe) from stdin_file and closes it
            execlp("head", "head", NULL); //this command will read from pipe
            close(fd[0]);
    }

    return 0;
}
