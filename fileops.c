#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<string.h>


int main() {
  char *filename = "file";
  int fd = open(filename,O_CREAT | O_WRONLY,0644);
  if (fd == -1){
    perror("somethiinf problematic happend");
    exit(EXIT_FAILURE);
  }
  char *data = "i added this to the file" ;
  write(fd,data,strlen(data));
  close(fd);
}

