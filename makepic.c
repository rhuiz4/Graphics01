#include <stdio.h>
#include <stdlib>
#include <fcntl.h>

int main(){
  char *beginning = "P3\n500 500\n255\n";
  int fd = open("mypic.ppm", O_CREAT | O_RDWR | O_APPEND, 0644);
  write(fd, beginning, sizeof(beginning+1));
  
  char *pixels;
  int i = 0;
  while (i < 500){

  }
}
