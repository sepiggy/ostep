#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int
main() {
  int x = 100;
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed!");
  } else if (rc == 0) {
    x = 1234;
    printf("the x is %d in child\n", x);
  } else {
    wait(NULL);
    x = 5678;
    printf("the x is %d in parent\n", x);
  }
  return 0;
}
