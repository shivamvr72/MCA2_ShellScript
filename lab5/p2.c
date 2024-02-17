#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	int x=7, y=30;
	pid_t pid;
	printf("Fork...\n");
	pid = fork();
	
	switch(pid){
		//child process
		case 0:
			printf("Child Process... \nPrinting Addition... \nDelay 1 sec...\n");
			sleep(1);
			printf("Addition : %d\n", x+y);
			break;
			exit(0);
		//error 
		case -1:
			printf("Fork Error!\n");
			break;
			exit(1);
		default:
			sleep(1.5);
			printf("Parent Process...\nPrinting multiplication... \n");
			sleep(5);
			printf("Delay 5 sec...\n");
			int mul = x*y;
			printf("Multiplication : %d \n", mul);
			exit(0);
			
	}
	return 0;
}

