//sn3
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <unistd.h>

int  main(){
    //creting 3 shared memory
    int shmid1 = shmget(IPC_PRIVATE, 10*(sizeof(int)), IPC_CREAT| 0744);
    int shmid2 = shmget(IPC_PRIVATE, 10*(sizeof(int)), IPC_CREAT| 0744);
    int shmid3 = shmget(IPC_PRIVATE, 10*(sizeof(int)), IPC_CREAT| 0744);
 
    //checking status
    if(shmid1 < 0  && shmid2 < 0 && shmid3 < 0){
        printf("shmid failed \n"); exit(1);
    }
    //creating attachment poiters
    int *s1 = shmat(shmid1, NULL, SHM_RND);
    int *s2 = shmat(shmid2, NULL, SHM_RND);
    int *s3 = shmat(shmid3, NULL, SHM_RND);

    int x=0, y=0;
    printf("Enter number x: ");
    scanf("%d", &x);
    printf("Enter number y: ");
    scanf("%d", &y);

    //child process creation 
    pid_t pid;

    pid = fork();
    if(pid < 0){
        printf("fork failed\n");
    }
    if(pid > 0){
        printf("Parent process...\n");
        //storing value into shared memory
        *s1 = x;
        *s2 = y;

        printf("control will be transfer to child...\n");
        sleep(2);
        printf("control back...\n");

        printf("value in z = %d \n", *s3);

        shmdt(s1);
        shmdt(s2);
        shmdt(s3);

        shmctl(shmid1, IPC_RMID, NULL);
        shmctl(shmid2, IPC_RMID, NULL);
        shmctl(shmid3, IPC_RMID, NULL);
    }
    if(pid == 0){
        printf("child process\n");
        printf("value of x = %d and y = %d \n", *s1, *s2);
        *s3 = *s1+*s2;
    }

    return 0;
}