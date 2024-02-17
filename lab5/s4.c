#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>


int main(){
	int exitval=0, exitstatus;
	switch(fork()){
		case 0: 
			printf("child: terminating with exit value %d\n", exitval);
		default:
			wait(&exitstatus);
			printf("parent: child Teminated with value %d\n", WEXITSTATUS(exitstatus));
			exit(20);
	}
}

