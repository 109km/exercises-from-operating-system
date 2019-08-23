#include <stdlib.h>
#include <stdio.h>

int main()
{
  int *data = NULL;
  data = (int *)malloc(100 * sizeof(int));
  data[100] = 0;
  printf("data:%d\n", data[100]);
  return 0;
}