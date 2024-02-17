#include <stdio.h>
//#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
int main(){
	system("ps");
	sleep(5); //delay time for further process
	//printing process id and parent process id
	printf("PID=%d, PPID=%d\n", getpid(), getppid());
	//printing userid and group user id 
	printf("UID=%d, GID=%d\n", getuid(), getgid());
	exit(0);
	
	return 0;
}
