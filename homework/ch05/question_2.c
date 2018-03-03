#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int
main() {
  int fd = open("question_2.out", O_WRONLY | O_TRUNC | O_CREAT, S_IRWXU);
  int rc = fork();
  char *s = "1234567890";
  if (rc < 0) {
    fprintf(stderr, "fork fail...");
  } else if (rc == 0) {
    // printf("the fd is %d in child\n", fd);
    for (int i=0; i<10000; i++)
      write(fd, s, strlen(s));
  } else if (rc > 0) {
    // wait(NULL);
    // printf("the fd is %d in parent\n", fd);
    for (int i=0; i<10000; i++)
      write(fd, s, strlen(s));
  }
  printf("FINISHED!");

  return 0;
}
