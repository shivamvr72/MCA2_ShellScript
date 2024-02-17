#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int shmid, stat;
    char *buf;
    int k, *val, i;

    struct shmid_ds sds;
    shmid = shmget(IPC_PRIVATE, 100, IPC_CREAT|0644);
    if(shmid == -1){
        printf("Error in shmget");
        exit(1);
    }
    buf = (char *) shmat(shmid, 0, SHM_RND);
    val = (int *) shmat(shmid, 0, SHM_RND);
    *val = 10;
    buf[0] = 'a';
    printf("%c\n", buf[0]);
    printf("%d\n", *val);

    shmdt(buf);
    shmdt(val);

    k=shmctl(shmid,IPC_RMID, NULL);
    if(k==-1){
        printf("Error in shmctl");exit(1);
        exit(2);
    }

}
