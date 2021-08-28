/**
 * need to run in linux environment
 * gcc -Wall ${file_name} -o ${out_filename} && ./${out_filename}
 */
#define _GNU_SOURCE
#include <sched.h>
#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define STACK_SIZE (1024 * 1024)

static char child_stack[STACK_SIZE];

char* const child_agrs[] = {"/usr/bin/bash", NULL};

int child_main(void* args) {
  printf("in child process\n");
  sethostname("NewNamespace", 12);
  execv(child_agrs[0], child_agrs);
  return 1;
}

int main(void) {
  printf("process start\n");
  int child_pid = clone(
      child_main, child_stack + STACK_SIZE,
      CLONE_NEWNS | CLONE_NEWPID | CLONE_NEWIPC | CLONE_NEWUTS | SIGCHLD, NULL);
  waitpid(child_pid, NULL, 0);
  printf("process exit\n");
  return 0;
}
