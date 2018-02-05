#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
  char *beginning = "P3\n500 500\n255\n";
  int fd = open("mypic.ppm", O_CREAT | O_RDWR | O_APPEND, 0644);
  write(fd, beginning, sizeof(beginning+1));
  
  char pixels[14];
  int r, g, b;
  int row = 0;
  int col = 0;
  while (row < 500){
    while (col < 500){
      r = rand() % 256;
      g = rand() % 256;
      b = rand() % 256;
      sprintf(pixels, "%d %d %d ", r, g, b);
      col++;
      write(fd, pixels, sizeof(pixels));
    }
    write(fd, "\n", sizeof("\n"));
    row++;
  }
  
  //write(fd, pixels, sizeof(pixels));
  close(fd);
}
