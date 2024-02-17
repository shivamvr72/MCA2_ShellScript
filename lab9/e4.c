#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv){
	//	char *arr[] = {"./e1", NULL};

	//taking argument from command line machanism
	
	//pass cmd argument like this =>   ./a.out wc wc -l t1.txt

	execvp(argv[1], &argv[2]);

	return 0;
}
