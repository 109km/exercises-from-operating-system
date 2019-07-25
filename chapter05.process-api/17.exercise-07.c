/**
 * @Question 编写一个创建子进程的程序，然后在子进程中关闭标准输出(STDOUT_FILENO)。
 * 如果子进程在关闭描述符后调用printf()打印输出，会发生什么？
 */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
  pid_t c_pid = fork();
  if (c_pid == 0)
  {
    printf("Hello, before close STDOUT_FILENO,child pid(%d)\n", getpid()); // 正常打印
    close(STDOUT_FILENO);
    printf("Hello, after close STDOUT_FILENO\n"); // 并不会打印出来
    sleep(2);
    exit(200);
  }
  else if (c_pid > 0)
  {
    int status;
    waitpid(c_pid, &status, 0);
    if (WIFEXITED(status) > 0) // 正常结束
    {
      printf("Child exited with code %d\n", WEXITSTATUS(status));
    }
    else if (WIFSIGNALED(status))
    {
      printf("Child terminated abnormally, signal %d\n", WTERMSIG(status));
    }
    printf("Exited parent process(pid:%d)\n", getpid());
  }
}