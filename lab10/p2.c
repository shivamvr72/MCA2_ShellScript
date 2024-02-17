//output redirection using dup
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int  main(){
    int fd1, fd2, nfd1;
    char *argv[] = {"cat", NULL};

    fd1 = open("t1.txt", O_RDONLY);
    fd2 = open("t2.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

    close(STDIN_FILENO);  //close std input steam for file no input from keyboard
    nfd1 = dup(fd1); //redirect input stream from file t1.txt
    printf("nfd1 = %d", nfd1); // allocates fd lowes available one here 4 
    //cz stdin accoupied by stdin(redirected to t1.txt so taking input from t1.txt so 0 is occupied )
    //2 by stdout and 3 by stderr 
    close(STDOUT_FILENO); //closes std output stream for file no output on display
    dup(fd2);//redirect ouput stream to file t2.txt
    // //will not be print as output in console
    printf("fd2 = %d \n", fd2);
    execvp(argv[0], argv); //perfors cat command and output redirected to file t2.txt
    close(fd1);
    close(fd2);
    return 0;
}