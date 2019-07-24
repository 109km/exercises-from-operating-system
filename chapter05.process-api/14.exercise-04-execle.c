/**
 * int execle(const char *path, const char *arg,..., char * const envp[]);
 *  path: 必须指定确定的可执行文件路径
 *  arg: 字符指针
 *  envp: 环境变量的字符指针数组
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  printf("Entering main process(pid:%d)\n", getpid()); // 可以执行
  char *cmd = "./14.exercise-04-extern-env";
  char *envp[] = {"AA=aa", "BB=bb", NULL};
  int ret = execle(cmd, "hello", NULL, envp);
  if (ret == -1)
  {
    perror("execle failed\n");
  }
  printf("exiting main..\n");  // 不执行
  return 0;
}