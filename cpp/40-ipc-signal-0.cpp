#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

void ouch(int sig) {
  printf("signal %d\n", sig);       // 打印接收到的信号量
  (void)signal(SIGINT, SIG_DFL);  // 修改SIGINT信号的处理程序为默认处理程序
}

int main(void) {
  (void)signal(SIGINT, ouch);
  while (true) {
    printf(".\n");
    sleep(1);
    
  }
  return 0;
}

// SIGHUP ：从终端上发出的结束信号
// SIGINT ：来自键盘的中断信号 ( ctrl + c )
// SIGKILL ：该信号结束接收信号的进程
// SIGTERM：kill 命令发出的信号
// SIGCHLD：标识子进程停止或结束的信号
// SIGSTOP：来自键盘 ( ctrl + z ) 或调试程序的停止执行信号。
