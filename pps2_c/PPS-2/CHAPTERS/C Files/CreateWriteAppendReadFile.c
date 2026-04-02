#include <stdio.h>
#include <stdlib.h>
int main()
{
  FILE *ptr1, *ptr2;

  // Create a file on your computer (filename.txt)
  ptr1 = fopen("RAJ.txt", "w");
  ptr2 = fopen("filename.txt", "a");

  // Write something in your FILE
  fprintf(ptr1,"Hello there!");
  fprintf(ptr1,"Hi there!"); //Changes if seperately re-executed

//READ (r, r+): Opens a file for reading. If the file doesn’t exist, the operation fails. You can use functions like fread() or fgets() to read data.
//WRITE (w, w+): Opens a file for writing. If the file exists, it overwrites its contents. If it doesn’t exist, a new file is created. Functions like fwrite() or fprintf() help write data.
//APPEND (a, a+): Opens a file for appending. If the file exists, new data is added at the end. If it doesn’t exist, a new file is created. You can use fwrite() or fprintf() for appending.


  fprintf(ptr2,"This is GHOSH");
  fprintf(ptr2,"\nThis is RAJ");


  // Close the file
  fclose(ptr1);
  fclose(ptr2);

  return 0;
}
