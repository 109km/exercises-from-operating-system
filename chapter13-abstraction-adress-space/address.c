#include <stdio.h>
#include <stdlib.h>

int MAX = 100;

void hello()
{
  printf("location of function hello: %p\n", (void *)hello);
}

int main()
{
  hello();
  printf("location of MAX : %p\n", (void *)&MAX);
  printf("location of code : %p\n", (void *)main);
  printf("location of heap : %p\n", (void *)malloc(2));
  int x = 3;
  int y = 4;
  printf("location of stack: %p | %p\n", (void *)&x, &y);
  return 0;
}
