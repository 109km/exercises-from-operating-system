#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  printf("hello world (pid:%d)\n", (int)getpid());

  /**
   * Parent process will get the number of child process's pid,
   * and the child process will get 0 here.
   * 
   * Processes's running order depends on the `OS scheduler`.
   */
  int rc = fork(); // The child process's code starts from here.
  if (rc < 0)
  {
    fprintf(stderr, "fork failed\n");
  }
  else if (rc == 0)
  {
    printf("hello,I am child (pid:%d)", (int)getpid());
  }
  else
  {
    printf("hello,I am parent of %d (pid:%d)\n", rc, (int)getpid());
  }
  return 0;
}
