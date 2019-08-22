#include <stdlib.h>
#include <stdio.h>

int main()
{
  int *data = malloc(100);
  data[100] = 0;

  printf("data: %d \n", data[100]);
  return 0;
}