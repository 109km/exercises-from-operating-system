#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX = 100;

void hello()
{
  int *x = malloc(sizeof(int) * 3);
  int *y = malloc(sizeof(int));
  printf("location of function hello: %p\n", (void *)hello);
  printf("location of x in hello: %p\n", x);
  printf("location of y in hello: %p\n", y);
}

char *copy(char *str)
{
  char *cstr = malloc(strlen(str) + 1);
  strcpy(cstr, str);
  return cstr;
}

int main()
{
  hello();
  printf("location of MAX : %p\n", (void *)&MAX);
  printf("location of code : %p\n", (void *)main);
  printf("location of heap : %p\n", (void *)malloc(2));
  int x = 3;
  double y = 4.0;
  void *z1 = malloc(sizeof(int));
  void *z2 = malloc(sizeof(int));
  printf("location of stack: %p | %p | %p | %p\n", &x, &y, z1, z2);
  printf("z1 - z2 = %ld\n", z1 - z2);
  char *text = "hello";
  char *ntext = copy(text);
  printf("copied string address: %p\n", ntext);
  free(ntext);
  return 0;
}
