/**
 * @Question 使用fork()编写另一个程序。子进程打印“hello”，父进程打印“goodbye”。
 * 应确保子进程始终先打印，并且不在父进程调用wait()来实现这一功能。
 * 
 * @Answer 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  pid_t childpid;
  int status;
  childpid = fork();
  if (childpid < 0)
  {
    fprintf(stderr, "fork failed\n");
  }
  else if (childpid == 0)
  {
    printf("This is child process, hello.\n");
    exit(EXIT_SUCCESS);
  }
  else
  {
    waitpid(childpid, &status, 0);
    printf("This is parent process, goodbye.\n");
    printf("Child process status is %d \n", status);
  }
  return 0;
}