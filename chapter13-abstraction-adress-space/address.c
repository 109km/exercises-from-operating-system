#include <stdio.h>
#include <stdlib.h>

int MAX = 100;

void hello()
{
  void *x = malloc(sizeof(int));
  void *y = malloc(sizeof(int));
  printf("location of function hello: %p\n", (void *)hello);
  printf("size of double in hello: %ld\n", (y - x));
}

int main()
{
  hello();
  printf("location of MAX : %p\n", (void *)&MAX);
  printf("location of code : %p\n", (void *)main);
  printf("location of heap : %p\n", (void *)malloc(2));
  int x = 3;
  double y = 4.0;
  int *z = malloc(sizeof(int));
  printf("location of stack: %p | %p | %p\n", &x, &y, z);
  return 0;
}
