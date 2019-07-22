#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
  int rc = fork();
  if (rc < 0)
  {
    fprintf(stderr, "fork failed\n");
  }
  else if (rc == 0)
  {
    close(STDOUT_FILENO);
    open("./p5.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU); // STDOUT_FILENO will be set a new value
    char *myargs[3];
    myargs[0] = argv[1];
    myargs[1] = argv[2];
    myargs[2] = NULL;
    execvp(myargs[0], myargs); // Outputs are redirected to STDOUT_FILENO
  }
  else
  {
    int wc = wait(NULL);
  }
  return 0;
}