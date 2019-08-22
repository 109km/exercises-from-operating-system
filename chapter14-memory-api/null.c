#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int *p = NULL;
  printf("before free p address: %p\n", p);
  free(p);
  printf("after free p address: %p\n", p);
  return 0;
}
