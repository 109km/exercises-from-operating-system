/**
 * int execlp(const char *file, const char *arg, ...);
 *  file: 指向要执行的命令的文件，可以省略式写法
 *  arg及后面的省略号: 等同于拆分的数组里的参数
 */

#include <stdio.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
  char *cmd = "ls";
  execlp(cmd, cmd, "-a", (char *)NULL);
  return 0;
}