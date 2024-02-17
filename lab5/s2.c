#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
	pid_t pid;
	printf("Before fork\n");
	
	pid = fork();
	if(pid>0){
		sleep(1);
		printf("parent process\n");
		printf("pid=%d, ppid=%d, child pid=%d\n", getpid(), getppid(), pid);
	}
	else if(pid==0){
		printf("child process\n");
		printf("pid=%d, ppid=%d\n", getpid(), getppid());
	}
	else{
		printf("Fork error\n");
		exit(1);
	}
	return 0;
}
