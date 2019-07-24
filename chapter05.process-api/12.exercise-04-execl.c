/**
 * int execl(const char *path, const char *arg,...);
 *  path: 与execv类似，这必须明确指定可执行文件的地址
 *  arg及省略号：等同拆分出来的数组
 */

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  char cmd[] = "/bin/ls";
  char *p_cmd = cmd;
  execl(p_cmd, p_cmd, "-a", (char *)NULL);
  return 0;
}