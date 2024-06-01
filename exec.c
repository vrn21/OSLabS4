#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>


int main(){
  pid_t p = fork();

  if (p<0){
    perror("fork failed");
  }

  if (p>0){
    printf("fork sucess %d\n" ,getpid());
    char *args2[] = {"ls","-l",NULL};
    execvp(args2[0],args);
    printf("ls completed\n");
   exit(EXIT_FAILURE); 
  }
  else{
    printf("parent waiting for child%d\n" ,getpid());
    wait(NULL);
    printf("child processes completed\n");
  }

}
