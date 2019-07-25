/**
 * @Question 对上一个练习进行修改，这次使用waitpid()。
 * 什么时候waitpid()有用？
 * 
 * pid_t waitpid(pid_t pid, int *status, int options);

waitpid()会暂时停止目前进程的执行, 直到有信号来到或子进程结束. 如果在调用wait()时子进程
已经结束, 则wait()会立即返回子进程结束状态值. 子进程的结束状态值会由参数status 返回, 而
子进程的进程识别码也会一快返回. 如果不在意结束状态值, 则参数status 可以设成NULL. 参数pid 
为欲等待的子进程识别码, 其他数值意义如下：
1、pid<-1 等待进程组识别码为pid绝对值的任何子进程.
2、pid=-1 等待任何子进程, 相当于wait().
3、pid=0 等待进程组识别码与目前进程相同的任何子进程.
4、pid>0 等待任何子进程识别码为pid 的子进程.
参数option 可以为0 或下面的OR 组合：
1、WNOHANG：如果没有任何已经结束的子进程则马上返回, 不予以等待；
2、WUNTRACED：如果子进程进入暂停执行情况则马上返回, 但结束状态不予以理会. 子进程的结束状态返回后存于status, 底下有几个宏可判别结束情况；
3、WIFEXITED(status)：如果子进程正常结束则为非0 值；
4、WEXITSTATUS(status)：取得子进程exit()返回的结束代码, 一般会先用WIFEXITED 来判断是否正常结束才能使用此宏；
5、WIFSIGNALED(status)：如果子进程是因为信号而结束则此宏值为真；
6、WTERMSIG(status)：取得子进程因信号而中止的信号代码, 一般会先用WIFSIGNALED 来判断后才使用此宏；
7、WIFSTOPPED(status)：如果子进程处于暂停执行情况则此宏值为真. 一般只有使用WUNTRACED时才会有此情况；
8、WSTOPSIG(status)：取得引发子进程暂停的信号代码, 一般会先用；
9、WIFSTOPPED 来判断后才使用此宏。

wait与waitpid区别
wait等待第一个终止的子进程，而waitpid可以通过pid参数指定等待哪一个子进程。
当pid=-1、option=0时，waitpid函数等同于wait，可以把wait看作waitpid实现的特例。
waitpid函数提供了wait函数没有提供的三个功能：
1、waitpid等待一个特定的进程，而wait则返回任一终止子进程的状态 。
2、waitpid提供了一个 wait的非阻塞版本，有时希望取得一个子进程的状态，  但不想进程阻塞。
3、waitpid支持作业控制。

 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
  pid_t cpid = fork();

  if (cpid == 0)
  {
    printf("This is child process(pid:%d)\n", (int)getpid());
    int i;
    for (i = 3; i > 0; i--)
    {
      printf("This is the child\n");
      sleep(1);
    }
    exit(3);
  }
  else if (cpid > 0)
  {
    // int *stat_val;
    // waitpid(cpid, stat_val, 0); // 用stat_val读取值
    // 上面这种写法是错误的，c语言中无法直接使用 int *p1 = 12
    // 指针变量后边必须跟的是地址，char *p1 = "abc"是可以的，
    // 因为双引号返回的是字符串地址。

    int stat_val;
    waitpid(cpid, &stat_val, 0); // 用 *stat_ptr读取值

    if (WIFEXITED(stat_val) > 0) // 正常结束
    {
      printf("Child exited with code %d\n", WEXITSTATUS(stat_val));
    }
    else if (WIFSIGNALED(stat_val))
    {
      printf("Child terminated abnormally, signal %d\n", WTERMSIG(stat_val));
    }
  }
  return 0;
}