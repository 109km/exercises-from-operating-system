#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  char cnum = *argv[1];
  int num = (cnum - '0');
  int i = 0;

  printf("num from cli: %d\n", num);

  int arr[5] = {1, 2, 3, 4, 5};
  int *ipp = malloc(sizeof(int) * num);
  int *cip = calloc(num, sizeof(int));

  printf("address before realloced : %p\n", ipp);

  void *re_address = realloc(ipp, 100);

  printf("address after realloced : %p\n", re_address);

  free(ipp);

  printf("address after free : %p\n", ipp);

}