#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>

int main(){
    char *text = "shivam rana";
    int smid = shmget(IPC_PRIVATE, 100, IPC_CREAT | 0644);

    if(smid == -1){
        printf("failed to create shared memory\n");
        exit(1);
    }

    pid_t pid = fork();

    if(pid == -1){
        printf("fork failed \n");
        exit(1);
    }


    char *p_ptr = shmat(smid, NULL, SHM_RND);
    int len = strlen(text);
    if(pid > 0){
        char *temp = p_ptr;
        for(int i=0; i<len; i++){
            *temp = text[i];
            temp++;
        }    
        *temp = '0';
        // while(*p_ptr != '#'){
            sleep(2);
        // }
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
        printf("\n");
        *t1 = '#';
    }

}
