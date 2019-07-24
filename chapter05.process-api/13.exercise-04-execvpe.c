/**
 * 
 * The execle() and execvpe() functions allow the caller to specify 
 * the environment of the executed program via the argument envp. 
 * The envp argument is an array of pointers to null-terminated strings and 
 * must be terminated by a NULL pointer. 
 * The other functions take the environment for the new process image 
 * from the external variable environ in the calling process.
 * 
 * int execvpe(const char *file, char *const argv[],char *const envp[]);
 *  file: 指向可执行文件的路径或者命令
 *  argv: 其他参数的数组
 *  envp: 环境变量的字符指针数组
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  char *file = "ls";
  char *args[] = {"-a"};
  char *evnp[] = {"AA=aa", "BB=bb", NULL};
  execvpe(file, args, evnp);
  return 0;
}