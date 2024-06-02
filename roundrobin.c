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

struct Node enquee(struct Node head, struct Process newp){
  struct Node ptr = head;
  struct Node* newNode = (Node*) malloc(sizeof(Node));
  
  newNode -> process = newp;
  if (front == NULL){
    fron = rear = newNode;
  }
  while (ptr->next != NULL){
    ptr = ptr->next;
  }


  return head;
}



int main(){}
