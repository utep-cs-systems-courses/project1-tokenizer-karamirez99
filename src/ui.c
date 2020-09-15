
#include <stdio.h>
#include <stdlib.h>

#define LINELIMIT 100

int main()
{
  char line[LINELIMIT];
  
  printf(">Enter a line\n");

  fgets(line, LINELIMIT, stdin);
  printf("%s\n", line);

  return 0;
}
