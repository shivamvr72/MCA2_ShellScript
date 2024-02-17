#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	printf("Coping file...\n");
	int buff[70];
	int fd1, fd2;
	int n;
		fd1 = open("test2.txt", O_RDONLY);
		fd2 = open("test1.txt", O_CREAT, O_WRONLY, O_TRUNC, 0700);
		
		

	return 0;
}


