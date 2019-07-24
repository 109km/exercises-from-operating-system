/**
 * 测试execle指定的环境变量
 */

#include <stdio.h>
#include <unistd.h>
extern char **environ;
int main(int argc, char *argv[])
{
  int i;
  for (i = 0; environ[i] != NULL; ++i)
  {
    printf("%s\n", environ[i]);
  }
  printf("exiting child(pid:%d)\n", getpid()); // pid与主进程相同，证明exec族的函数实际上是替换了主进程内容。
  return 0;
}