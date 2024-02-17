#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv){
	//execv(path variable ptr of executable binary , NULL terminated array ptr);  here v stads for vector
	
//	char *pathv = "/bin/wc";
//	char *args[] = {"/home/shivam/oslp/lab9", "-l", "t1.txt", NULL};

	char *pathv = "/bin/cat";
	char *args[] = {"/home/shivam/oslp/lab9", "t1.txt", NULL};

	pid_t pid;
	pid = fork();
	
	if(pid == 0){
		printf("child process...\n");
		printf("execvp() for cat executable...\n"); //cmd args
		execvp(argv[1], &argv[2]);
	}else if(pid > 0){
		sleep(1);
		printf("parent process...\n");
		printf("execv() for cat executable...\n");
		execv(pathv, args);
	}	
	return 0;
}

