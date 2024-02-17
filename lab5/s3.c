#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	pid_t pid;
	int x=100;
	printf("before fork\n");
	pid = fork();
	switch(pid){
		case -1:printf("fork error...\n");
			exit(1);
		case 0:
			printf("child process...\n");
			printf("initial value of x=%d\n", x);
			x=200;
			printf("new value of x=%d\n", x);
			break;
			exit(0);
		default:
			sleep(2);
			printf("parent process...\n");
			printf("value of x=%d\n",x);
			exit(0);
			
	}
	return 0;
}
