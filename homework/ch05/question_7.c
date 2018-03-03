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
    close(STDOUT_FILENO);
    printf("hello unix.\n");
  } else {
    printf("this line in the parent process.\n");
  }
  return 0;
}
