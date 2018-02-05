#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int main(){

  //writes header
  char *beginning = "P3\n600 600\n255\n";
  int fd = open("mypic.ppm", O_CREAT | O_RDWR, 0644);
  write(fd, beginning, strlen(beginning));

  //vars
  char pixels[255];
  int r, g, b;
  int row;
  int col;

  //generates color
  for(row = 0; row < 600; row++){
    for(col = 0; col < 600; col++){

      //generates random rbg
      r = 0;//(row) % 500;
      g = 0;//(col) % 500;
      b = 0;//(row + col) % 500;
      
      int i = row % 60;
      int j = col % 60;

      /*
      if (i == 20 || i == 40 || i == 0 || row == 500 - col){
        r = 0;
        g = 0;
        b = 0;
      }
      */
      
      if (i < 20)
	r += col;
      else if (i < 40)
	g += col;
      else
	b += col;
      
      if (j < 20)
        r += row;
      else if (j < 40)
        g += row;
      else
        b += row;
      
      sprintf(pixels, "%d %d %d", r, g, b);

      //end of pixel
      if (col != 599){
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
