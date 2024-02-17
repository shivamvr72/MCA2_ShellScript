#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	pid_t pid;
	printf("fork...\n");
	pid =fork();	
	if(pid>0){
	
		printf("parent process...\n");
		printf("PID : %d \n", getpid());
		printf("PPID: %d \n", getppid());
		exit(0);
	}
	else if(pid==0){
//		sleep(3);
		printf("\nChild Process...\n");
		printf("PID : %d \n", getpid());
		printf("PPID: %d \n", getppid());
		exit(0);
	}
	else{
		printf("fork error...!\n");
		exit(1);
	}
	
	return 0;
}
