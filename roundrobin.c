#include<stdio.h>
#include<stdlib.h>


struct Process {
  int pid;
  int at;
  int bt;
  int ct;
  int tat;
  int wt;
  int rt;
  int status;
};
struct Node {
  struct Node* next;
  struct Process process;
};

void enquee(struct Node* head, struct Node* rear,struct Process newp){
  struct Node* ptr = head;
  struct Node* newNode = (Node*) malloc(sizeof(Node));
  
  newNode -> process = newp;
  if (front == NULL){
    front = rear = newNode;
  }else{
    rear->next = newNode;
  }
  return head;
}

struct Process dequeue(struct Node* head,struct Node* rear){
  struct Node* release = struct Node head;
  struct Node head = head->next;
  return release->process;
}


void roundrobin(struct Process list[10], struct Node head,struct Node rear,int t){
 
 
 
  for(int i = 0; i<9;i++){
    for(int j = 0; j<10-1-i; j++){
      if(list[j].at > list[j+1].at){
        struct Process temp = list[j];
        list[j] = list[j+1];
        list[j+1] = list[j];
      }
    }
  }
    
  struct Node* head = NULL;
  struct Node* rear = NULL;

  //for(int k =0; k<10; k++){
  //  enqueue(head,rear,list[k]);
  //}
  
  int completed = 0;
  int current_time = 0;
  enqueue(head,rear,list[0]);

  while(completed < n){

    while (head == NULL){
         for(int k = 0; k <10; k++){
             if (list[k].status && list[k].at < current_time){
               enqueue(head,rear,list[k]);
             }
         } 
       }
      
    struct Process current = dequeue(head,rear);
    if (current.rt > t){
      current.rt = current.rt - t;
      enqueue(head,rear,current);
      current_time = current_time + t;
    }else if (current.rt <= t){
      current.rt = 0;
      current.ct = current_time;
      current.status = 1;
    }
       
  }

}

int main(){}
