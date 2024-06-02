#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/wait.h>
#include<sys/shm.h>

int main(){
  key_t key = ftok(".",'x');
  int shmid = shmget(key,1024,0666 | IPC_CREAT);

  pid_t p = fork();
  if (p > 0){
    char *shm_ptr = shmat(shmid,NULL,0);
    strcpy(shm_ptr,"hello world!, wrtten from parent");
    shmdt(shm_ptr);
    wait(NULL);
    shmctl(shmid,IPC_RMID,NULL);
    
  }
  else if ( p == 0 ){
    char *shm_ptr = shmat(shmid,NULL,0);
    printf("data read from shared mem is : \n %s", shm_ptr);
    shmdt(shm_ptr);
    //exit(0);
  }
}
