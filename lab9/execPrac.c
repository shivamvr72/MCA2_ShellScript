#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	printf("Exec System calls..\n");
	
	pid_t pid;
	pid = fork();
	if(pid < 0){
		printf("Fork Error :( ..\n");
	}else if(pid == 0){

		printf("child process...\n");
		printf("execlp() for cat executable...\n");
		execlp("cat", "cat", "t1.txt", "t2.txt", NULL);
	}else if(pid > 0){
		sleep(1);
		printf("parent process...\n");
		printf("execl() for cat executable...\n");
		execl("/bin/cat", "cat", "t1.txt", "t2.txt", NULL);
	}
}

