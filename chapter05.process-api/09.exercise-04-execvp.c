/**
 * @Question 编写一个调用fork()的程序，然后调用某种形式的exec()来运行程序 /bin/ls。
 * exec()的所有变体，包括execl()、execle()、execlp()、
 * execv()、execvp()和execvpe()。
 * 为什么同样的基本调用会有这么多变种？
 * 
 * @Answer
 * exec族下的所有函数都会直接新建一个process替代掉当前process，
 * 所以只会执行新process里的代码。
 * 
 * 所有变体可以分为4种：
 * 带v的：参数通过字符串指针数组来传递
 * 带l的：参数是list形式，可以分割开来
 * 带p的：执行的指令如果是简写，会先从PATH变量中寻找相应的执行文件。
 * 带e的：可以自定义环境变量，传递给要执行的二进制文件。
 * 
 * int execvp (const char *file, char *const argv[]);
 *  file: 指向要执行的文件
 *  argv: 一个字符串指针数组，必须以NULL结尾
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{

  printf("hello,I am main process."); // 这一行不会被执行

  char *args[] = {"ls", NULL};
  execvp(args[0], args);
  return 0;
}