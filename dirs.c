#include<stdio.h>
#include <dirent.h>

int main(void)
{
  DIR *dir = opendir(".");
  struct dirent *entry;
  printf("THe contents of the directory are: \n");
  while( (entry = readdir(dir)) != NULL){
    printf("%s \n",entry->d_name);
  }
  closedir(dir);

} 
