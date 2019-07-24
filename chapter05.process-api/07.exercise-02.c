/**
 * @Question 编写一个打开文件的程序（使用open()系统调用），然后调用fork()创建一个新进程。
 * 子进程和父进程都可以访问open()返回的文件描述符吗？
 * 当他们并发写入文件时会发生什么？
 * 
 * @Answer 
 * 1. 都能访问文件描述符
 * 2. 会根据父进程和子进程执行的先后顺序向文件中写入数据
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[])
{
  close(STDOUT_FILENO);
  int fd = open("./exercise-07.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
  int rc = fork();
  if (rc < 0)
  {
    fprintf(stderr, "fork failed\n");
  }
  else if (rc == 0)
  {
    printf("hello, this is child process, I am writing the file.."); // 不执行
    char *myargs[3];
    myargs[0] = strdup("wc");
    myargs[1] = strdup("07.exercise-02.c");
    myargs[2] = NULL;
    execvp(myargs[0], myargs);
  }
  else
  {
    printf("hello, this is parent process, I am writing the file.."); // 不执行
    char *myargs[3];
    myargs[0] = strdup("wc");
    myargs[1] = strdup("06.exercise-01.c");
    myargs[2] = NULL;
    execvp(myargs[0], myargs);
  }
  return 0;
}