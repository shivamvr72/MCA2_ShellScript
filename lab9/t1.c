#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	char *args[] = {"wc", "wc", "t1.txt", NULL};
	execvp(args[0], args);
	return 0;
}
