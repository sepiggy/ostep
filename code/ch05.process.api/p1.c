#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main() {
  printf("hello world (pid:%d)\n", (int) getpid());
  int rc = fork();
  if (rc < 0) { // fork failed; exit
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) { // child (new process)
    printf("hello, I am child (pid:%d)\n", (int) getpid());
    printf("the fork returning value in the child process is %d\n", rc);
  } else { // parent goes down this path (main)
    printf("hello, I am parent of %d (pid:%d)\n", rc, (int) getpid());
    printf("the fork returning value in the parent process is %d\n", rc);
  }
  return 0;
}

