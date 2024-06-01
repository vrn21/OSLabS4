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
  char *data = "i added this to the file and this too";
  write(fd,data,strlen(data));
  close(fd);

  int fr = open(filename,O_RDONLY);
  char buffer[100];
  ssize_t bytes_Read = read(fr,buffer,sizeof(buffer));
  if (bytes_Read > 0){
    printf("read efrom %s,\n",buffer);
  }
  close(fr);
}

