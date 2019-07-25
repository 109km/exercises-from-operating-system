/**
 * @Answer 创建两个子进程，并使用pipe()系统调用，将一个
 * 子进程的标准输出连接到另一个子进程的标准输入。
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
  pid_t c_pid1 = fork();
  pid_t c_pid2 = fork();
  int fd[2];

  if (pipe(fd) < 0)
  {
    printf("pipe create error ");
    return -1;
  }
  if (c_pid1 == 0)
  {
    close(fd[0]);
    printf("Process 1(pid:%d)\n", getpid());
    write(fd[1], "Hello, this is process 1\n", 12);
    sleep(1);
  }
  else if (c_pid2 == 0)
  {
    close(fd[1]);
    char line[12];
    int n = read(fd[0], line, 12);
    printf("Process 2(pid:%d)\n", getpid());
    write(STDOUT_FILENO, line, n); //子进程读取数据
    sleep(2);
  }
  else if (c_pid1 > 0 && c_pid2 > 0)
  {
    printf("Parent process(pid:%d)\n", getpid());
  }
  return 0;
}