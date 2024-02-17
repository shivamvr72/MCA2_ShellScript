//sn1
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>

int main(){ 
    //creting text
    char *text = "shivam rana";
    //creating shared memory
    int smid = shmget(IPC_PRIVATE, 100, IPC_CREAT | 0644);
    //cheking status
    if(smid == -1){
        printf("failed to create shared memory\n");
        exit(1);
    }
    //fork ready
    pid_t pid = fork();
    //fork status check
    if(pid == -1){
        printf("fork failed \n");
        exit(1);
    }
    //attaching with shared memory pointer
    char *p_ptr = shmat(smid, NULL, SHM_RND);
    int len = strlen(text);
    if(pid > 0){
        //parent storing character array
        char *temp = p_ptr;
        for(int i=0; i<len; i++){
            *temp = text[i];
            temp++;
        }
        *temp = '0';

        sleep(2);

        while(*p_ptr != '#'){
            printf("%c", *p_ptr);
            p_ptr++;
        }

        printf("\n");

        shmdt(p_ptr);
        shmctl(smid, IPC_RMID, NULL);
    }
    if(pid == 0){
        printf("child\n");
        char *t1 = p_ptr;
        while(*t1!= '0'){
            printf("%c", *t1);
            t1++;
        }
        char *txt1 = " hey";
        for(int i=0; i<5; i++){
            *t1 = txt1[i];
            t1++;
        }
        printf("\n");
        *t1 = '#';
    }
}