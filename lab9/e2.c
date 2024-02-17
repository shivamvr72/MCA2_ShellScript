#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	
	//	execlp(); uses path from enviroment variable so no need to write whole path of executalbe file
	// command are executable files in linux 
	//execlp("e1", "e1", NULL); it won't work because the path of e1 is not saved in environment vairbles 
	//execl("/home/shivam/oslp/e1", "e1", NULL); //so need specify full path 
	pid_t pid;
	pid = fork();
	
	if(pid > 0)	
		execlp("wc", "wc", "-lc", "t1.txt", NULL);
	else if(pid == 0)
		execlp("cat", "cat", "t1.txt", NULL);
	
	printf("finished..\n");
	return 0;
}	
