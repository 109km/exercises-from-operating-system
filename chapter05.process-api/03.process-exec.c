#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
  printf("hello world (pid:%d)\n", (int)getpid());
  int rc = fork();
  if (rc < 0)
  {
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (rc == 0)
  {
    printf("hello, I am child (pid:%d)\n", (int)getpid());
    char *myargs[3];
    myargs[0] = strdup("wc");
    myargs[1] = strdup("03.process-exec.c");
    myargs[2] = NULL;
    execvp(argv[0], argv);
    printf("This shouldn't print out\n");
  }
  else
  {
    int wc = wait(NULL);
    printf("hello, I am parent of %d (wc:%d) (pid:%d)\n", rc, wc, (int)getpid());
  }
  return 0;
}