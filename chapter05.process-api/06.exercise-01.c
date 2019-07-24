/**
 * @Question 编写一个调用fork()的程序。在调用fork()之前，让主进程访问一个变量（例如x）并将其值设置为某个值（例如100）。
 * 子进程中的变量有什么值？
 * 当子进程和父进程都改变x的值时，会发生什么？
 * 
 * @Answer 无法提前确定x值，因为无法预知父进程和子进程哪个先执行。
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  int x = 100;
  int rc = fork();
  if (rc < 0)
  {
    fprintf(stderr, "fork failed\n");
  }
  else if (rc == 0)
  {
    x = 90;
    printf("hello,this is child process, and setting x to %d\n", x);
  }
  else
  {
    x = 110;
    printf("hello, this is parent process, and setting x to %d\n", x);
  }

  return 0;
}