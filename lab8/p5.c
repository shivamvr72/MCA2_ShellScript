#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(){
    int fd[2], n;
    char str[100], buf[100];

    pipe(fd);

    pid_t pid;

    pid =fork();
    if(pid < 0){
        printf("fork error\n");
        exit(1);
    }else if(pid == 0){
        sleep(5);
        close(fd[1]); 
        int cnt=0;
        printf("child process ready to read...\n");
        read(fd[0], buf, sizeof(str));
        for(int i=0; i<strlen(buf); i++){
            if(buf[i] == 'a'|| buf[i]=='e'|| buf[i]=='i' || buf[i] == 'o' || buf[i] == 'u'){
                cnt++;
            }
        }
        printf("%s\n", buf);
        printf("volwels : %d \n", cnt);
        close(fd[0]);
        exit(0);
    }else{
        printf("Parent process writes...\n");
        close(fd[0]);
        printf("write some text withing: ");
        scanf("%[^\n]", str);
        write(fd[1], str, sizeof(str));
        printf("\n");
        close(fd[1]);
    }

    return 0;
}