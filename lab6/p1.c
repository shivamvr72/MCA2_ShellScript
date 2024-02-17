#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	int buff[50];
	int fd; //fd for file directory
	int n; //for read character store
	
	//to take input and store into file 
	
	fd = open("test1.txt", O_CREAT | O_WRONLY | O_TRUNC , 0600);
	printf("Write Something in file : ");
	fgets(buff, 50, stdin);
	write(fd, buff, sizeof(buff));
	
	//to read the file 
	
	fd=open("test1.txt", O_RDONLY);
	n = read(fd, buff, sizeof(buff));
	printf("Size OF File : %d\n", n);
	printf("Content In file at buffer size : %s\n",buff);
	
	return 0;
}
