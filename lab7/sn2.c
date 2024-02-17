// sn2
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(){
    int shmid;
    //creating shared memory 
    shmid = shmget(IPC_PRIVATE, 10*sizeof(int), IPC_CREAT| 0644);
    //check shmid 
    if(shmid < 0){
        printf("Shmid error\n");
        exit(1);
    }
    //attchment pointer for shared memory
    int *sh_ptr = (int*) shmat(shmid, NULL, SHM_RND);

    printf("Enter value1 : ");
    scanf("%d", sh_ptr);
    //for child process
    pid_t pid;
    pid  = fork();

    
    if(pid < 0){
        printf("fork failed\n");
        exit(1);
    }
    if(pid > 0){
        printf("contol will be transfer to child process...\n");
        sleep(2);

        printf("parent control back...\n");
        printf("parent value : %d ", *sh_ptr);

        printf("\n");

        shmdt(sh_ptr);
        int id = shmctl(shmid, IPC_RMID, NULL);
    }
    if(pid == 0){
        printf("child process \n");
        int *t1 = sh_ptr;

        int value = *t1;
        printf("value in shared memory : %d \n", value);
        *t1 = (value*value);
    }
}
