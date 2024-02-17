#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int main(){
    int in,out;

    char *argval[] = {"cat", NULL };

    in = open("in.txt", O_RDONLY);
    out = open("out.txt", O_CREAT | O_WRONLY | O_TRUNC, 0600);
    //close(STDIN_FILENO);
    dup2(in, 0); //it will coloses std input (key-board means 0 == STDIN_FILENO ) takes input from file by duplicating 'in' to  STDIN_FILENO
    printf("in %d \n", in);
    // close(STDIN_FILENO);
    dup2(out, 1); //it will closes output on console (not display in terminal/consol by closing 1 == STDOUT_FILENO ) and duplicates 1 to fd 'OUT' to perform redirection
    //...so cat data will be display in out.txt file insted of display
    execvp(argval[0], argval);

    close(in);
    close(out);
    return 0;
}