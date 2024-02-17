#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

int main(){
    int fd, n,cnt=0;
    char  buf[100];
    fd = open("test7.txt", O_RDONLY);
    n = read(fd, buf, 100);

    for(int i=0; i<n; i++){
        if(buf[i] == ' '){
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}