#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

int main(){
	int fd, n;
	char buff[100];
	fd = open("paragraph.txt", O_CREAT | O_WRONLY | O_TRUNC, 0700);
	fgets(buff, 100, stdin);
	write(fd, buff, strlen(buff));
	close(fd);
	
	fd = open("paragrpaph.txt" , O_RDONLY);
	read(fd, buff, strlen(buff));
	
	int len = strlen(buff), cnt=0;
	for(int i=0; i<len; i++){
		if(buff[i] == 'a' || buff[i] == 'i' || buff[i] == 'o' || buff[i] == 'e' || buff[i] == 'u'){
			cnt++;
		}
	}
	
	close(fd);
	printf("vowel = %d\n", cnt);
	return 0;
}

