// program to get shared memory id

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>


int main(){
    int shmid;
    shmid = shmget(IPC_PRIVATE, 2048, IPC_CREAT|0644);
    if(shmid==-1){
        printf("shared memory creation error!\n");
        exit(1);
    }else{
        printf("shmid = %d\n", shmid);
    }
    return 0;
}