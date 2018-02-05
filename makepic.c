#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int main(){

  //writes header
  char *beginning = "P3\n500 500\n255\n";
  int fd = open("mypic.ppm", O_CREAT | O_RDWR, 0644);
  write(fd, beginning, strlen(beginning));

  //vars
  char pixels[255];
  int r, g, b;
  int row;
  int col;

  //generates color
  for(row = 0; row < 500; row++){
    for(col = 0; col < 500; col++){

      //generates random rbg
      r = rand() % 256;
      g = rand() % 256;
      b = rand() % 256;

      sprintf(pixels, "%d %d %d", r, g, b);

      //end of pixel
      if (col != 499){
	strcat(pixels, " ");
      }

      //writes row
      write(fd, pixels, strlen(pixels));
    }

    //writes new line
    write(fd, "\n", strlen("\n"));
  }
  close(fd);
}
