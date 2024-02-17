#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <string.h>
#include <unistd.h>

int main(){
    int shmid;
    //creating shared memory
    shmid = shmget(IPC_PRIVATE, 100, IPC_CREAT| 0644); //return intiger ;for server side not for client and ipc_private mostly/only use for the child and parent process

    //diffent from the syllabus
    // key_t k; //creation of key
    // shmid = shmget(k, 100, IPC_CREAT | 0666); //server side
    // shmid = shmget(k, 100, 0666); //client side tho client don't crete it so no creat flag is used
    //end 

    //end of creting shared memory 
    
    if(shmid == -1){ 
        printf("shm shared memory creation error\n");
        exit(1);
    }
    char *c_arr;
    //attachment of shared memory
    char *shm_ptr = (char*) shmat(shmid, NULL, 0); //returns pointer if fails then negative int

    pid_t pid;
    pid = fork();
    if(pid == -1){
        printf("Frok error\n");
    }
    if(pid == 0){
        printf("in child stroring value in shared memroy \n");
        strcpy(c_arr, "shivam");
        c_arr = shm_ptr;

        
    }else if(pid > 0){
        printf("parent reading from shared memory\n");
        sleep(1);
        printf("%s\n", c_arr);
    }
    // printf("parent process reading\n");
//    shmdt(shm_ptr);
 //   shmctl(shmid, IPC_RMID, NULL);
    
    

    //detach shared memory
    shmdt(shm_ptr); //if fails to detach return non zero value !=0 if fails

    //remove shared memory
    shmctl(shmid, IPC_RMID, NULL);



    return 0;
}
