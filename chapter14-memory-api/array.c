#include <stdlib.h>
#include <stdio.h>

int main()
{
  int *data = NULL;
  data = (int *)malloc(100 * sizeof(int));

  for (int i = 0; i < 100; i++)
  {
    data[i] = i;
  }

  printf("data:%p\n", data);
  printf("data[50]: %d\n", data[50]);
  free(data);
  printf("after free:%d\n", data[50]);
  return 0;
}