#include<unistd.h>
#include<stdio.h>


int main(){
  pid_t p = fork();
  if (p > 0){
    printf("fork created %d \n",getpid());
    fork();
    printf("fork created %d \n",getpid());
  }
  if (p == 0) {
    printf("it is the parent over here %d\n",getpid());
  }
   if(p < 0){
    printf("somthing problematic happend\n");
  }
  return 0;
}
