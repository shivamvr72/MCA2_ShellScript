#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main(){
	
	pid_t pid;
	pid = fork();
	if(pid == 0){
	// execl() takes path of executable binary file
		printf("in child\n");
		execl("/bin/wc", "wc", "-l", "t1.txt", NULL); //list of argument must be terminated with NULL
	
	}else{
		sleep(1);
		printf("in parent\n");
		execl("/bin/cat", "cat", "t1.txt", "t2.txt", NULL);
	}
	printf("finished..\n");
	return 0;
}
