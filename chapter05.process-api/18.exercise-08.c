/**
 * @Answer 创建两个子进程，并使用pipe()系统调用，将一个
 * 子进程的标准输出连接到另一个子进程的标准输入。
 * 
 * 
  int pipe(int fds[2]);
  Parameters :
  fd[0] will be the fd(file descriptor) for the 
  read end of pipe.
  fd[1] will be the fd for the write end of pipe.
  Returns : 0 on Success.
  -1 on error.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MSGSIZE 64

int main()
{

  int fd[2];
  int nbytes;
  char inbuf[MSGSIZE];
  int status;
  pid_t c_pid;

  if (pipe(fd) < 0)
  {
    exit(1);
  }

  // Child process will write
  c_pid = fork();
  if (c_pid == 0)
  {
    close(fd[0]);
    printf("Child process is writing.\n");
    char *msg = "Hello, this message is from child.";
    write(fd[1], msg, MSGSIZE);
    printf("Child process finished writing.\n");
  }
  // Parent process will read
  else if (c_pid > 0)
  {
    wait(NULL);
    close(fd[1]);
    printf("Parent process is reading.The message is below:\n");
    while ((nbytes = read(fd[0], inbuf, MSGSIZE)) > 0)
    {
      printf("%s\n", inbuf);
    }
    if (nbytes != 0)
    {
      exit(2);
    }
    printf("Parent process finished reading.\n");
  }

  return 0;
}