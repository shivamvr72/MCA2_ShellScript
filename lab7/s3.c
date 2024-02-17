#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

int main(){
    int i, shmid, shmid2, id, id2, *arr;
    char *buf;
    pid_t pid;
    struct shmid_ds sds;
    shmid = shmget(IPC_PRIVATE, 10, IPC_CREAT| 0644);
    shmid2 = shmget(IPC_PRIVATE,  10*sizeof(int), IPC_CREAT| 0644);

    if(shmid == -1){
        printf("shmget error");
        exit(1);
    }
    arr = (int *) malloc(5*sizeof(int));
    buf = (char *) malloc(3*sizeof(char));
    
    arr = (int *) shmat(shmid2, 0, SHM_RND);
    buf = (char *) shmat(shmid,0,SHM_RND);

    strcpy(buf, "SVR");
    for(int i=0; i<5; i++){
        arr[i] = i+1;
    }
    pid = fork();

    if(pid==0){
        strcpy(buf, "svr");
        arr[2] =20;
    }else if(pid>0){
        sleep(2);
        for(i=0; i<3; i++){
            printf("%c", buf[i]);
        }
        printf("\n");
        for(i=0; i<5;i++)
            printf("%d ", arr[i]);
        printf("\n");
    }else{
        printf("fork error\n");
        exit(1);
    }
    shmdt(buf);
    shmdt(arr);
    id = shmctl(shmid, IPC_RMID, NULL);
    id2 = shmctl(shmid, IPC_RMID, NULL);

}

// shmget = create shared memory
// shmat = attach to process
// shmdt = shared memory detached
// shmctl = remove shared memory
