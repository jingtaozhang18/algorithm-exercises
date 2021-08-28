#include <stdio.h>
#include <unistd.h>

int main(void) {
  pid_t fpid;
  int count = 0;
  fpid = fork();
  if (fpid < 0)
    printf("error in fork\n");
  else if (fpid == 0) {
    printf("I am child, process id is %d\n", getpid());
  } else {
    printf("I am parent, process id is %d\n", getpid());
  }
  return 0;
}