#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main() {
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed.\n");
    exit(1);
  } else if (rc == 0) {
    int pid = (int) wait(NULL);
    printf("the returning of wait is %d\n", (int) pid);
    printf("the pid is %d in the child\n", (int) getpid());
  } else {
    // int pid = (int) wait(NULL);
    // printf("the returning of wait is %d\n", (int) pid);
    printf("the pid is %d in the parent\n", (int) getpid());
  }
  return 0;
}
