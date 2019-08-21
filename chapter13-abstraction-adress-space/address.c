#include <stdio.h>
#include <stdlib.h>

int MAX = 100;

void hello()
{
  int x = 0;
  printf("location of function hello: %p\n", (void *)hello);
  printf("location of x in hello: %p\n", (void *)&x);
}

int main()
{
  hello();
  printf("location of MAX : %p\n", (void *)&MAX);
  printf("location of code : %p\n", (void *)main);
  printf("location of heap : %p\n", (void *)malloc(2));
  int x = 3;
  int y = 4;
  int *z = malloc(sizeof(int));
  printf("location of stack: %p | %p | %p\n", &x, &y, z);
  return 0;
}
