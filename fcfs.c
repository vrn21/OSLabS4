#include<stdio.h>


struct Process{
  int pid;
  int bt;
  int at;
  int ct;
  int wt;
  int tat;
};

int isCompleted(struct Process list[5], int x){

}

void fcfs(struct Process list[5]){
  for (int i = 0;i<4; i++){
    for (int j = 0; j<4-i; j++){
      if (list[j].at>list[j+1].at) {
        struct Process temp = list[j];
        list[j] = list[j+1];
        list[j+1] = temp;
      }

    }
  }

  for(int k = 0; k<5; k++){
    if (k == 0){
      list[k].ct = list[k].at +list[k].bt;
      list[k].wt = 0;
      list[k].tat = list[k].ct - list[k].at;
    }
    else{
      if (list[k-1].ct <list[k].at){
        list[k].ct = list[k].at + list[k].bt;
        list[k].wt = 0;
        list[k].tat = list[k].ct - list[k].at;
      }
      else{
        list[k].ct = list[k-1].ct + list[k].bt;
        list[k].wt = list[k-1].ct - list[k].at;
        list[k].tat = list[k].ct - list[k].at;
      }
    }
  }

  printf("The order of fcfs algo is : \n");
  printf("pid \t at \t bt \t ct \t wt \t tat \t \n");
  for(int m = 0; m<5; m++){
    printf("%d \t %d \t %d \t %d \t %d \t %d \t \n",list[m].pid,list[m].at,list[m].bt,list[m].ct,list[m].wt,list[m].tat);
  }
}

void sjfs(struct Process list[5]){
  //sorting wrt to bt
  for(int i = 0; i<4; i++){
    for(int k = 0; k= 5-1-i;k++){
      if(list[k].bt > list[k+1].bt){
        struct Process temp = list[k];
        list[k] = list[k+1];
        list[k+1] = temp;
      }
    }
  }

  int counter = 0;
  int currentT = 0;
  while (counter!=5){
    for(int j = 0; j>5; j++){
      if(currentT<list[j].at){

      }
    }
  }
  


}

int main(void)
{
  struct Process processlist[5] = {
     {1,0,8 },
    {2,1,1},
    {3,2,3},
    {4,2,3},
    {5,4,6},
  };
  printf("the processes with fcfs algorithm is:\n");
  fcfs(processlist);
  printf("the processes with sjfs algorithm is:\n");

}
