#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	pid_t pid;
	int a=10, b=20;
	
	printf("Fork...\n");
	pid=fork();
	
	switch(pid){
		case 0:
			printf("child process...\n");
			printf("initial value of a=%d, b=%d :\n", a,b);
			a=20, b=30; //child process changing value.
			printf("new value of a=%d, b=%d\n", a,b);
			break;
			exit(0);
		case -1:
			printf("fork error...\n");
			exit(1);
		default:
			sleep(1);
			printf("checking value of a and b...\n");
			printf("a=%d, b=%d\n", a,b);
			exit(0);
	}
	return 0;
}
