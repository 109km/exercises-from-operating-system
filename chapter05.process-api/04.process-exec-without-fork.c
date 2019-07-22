#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
  printf("hello,I am main process(pid:%d)\n", (int)getpid());
  char *myargs[3];
  myargs[0] = argv[1];
  myargs[1] = argv[2];
  myargs[2] = NULL;
  execvp(myargs[0], myargs);
  printf("This shouldn't print out\n");
  return 0;
}