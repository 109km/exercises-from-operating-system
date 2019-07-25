/**
 * @Question 在父进程中使用wait()，等待子进程完成。
 * wait()返回什么？ 
 * 如果在子进程中使用wait()会发生什么？
 * 
 * @Answer
 * wait()返回的是子进程的pid
 * 子进程中调用wait()由于没有自己的子进程，所以wait()返回值是-1
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{

  pid_t rc = fork();

  if (rc == 0)
  {
    int cpid = wait(NULL);
    printf("In child process(pid:%d), and pid is %d\n", getpid(), cpid);
  }
  else if (rc > 0)
  {
    int cpid = wait(NULL);
    printf("In parent process(pid:%d)\n", getpid());
    printf("And child process's pid is %d\n", cpid);
  }
  else
  {
    fprintf(stderr, "fork failed");
  }

  return 0;
}