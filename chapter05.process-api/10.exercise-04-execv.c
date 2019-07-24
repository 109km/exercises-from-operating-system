/**
 * int execv(const char *path, char *const argv[]);
 *  path: 指向要执行的命令的目录
 *  argv: 一个字符串指针数组，必须以NULL结尾
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  char *args[] = {"/bin/ls", NULL}; // 命令如果是 ls 用execvp可以执行，而这里必须用完整的路径
  execv(args[0], args);
  return 0;
}