#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]) {

  int p[2];
  pipe(p);

  write(p[1], "ping", 4);
  close(p[1]);

  int pid = fork();
  if (pid > 0) {
    wait((int *)0);
    char *s = "";
    read(p[0], s, 4);
    close(p[0]);
    //    fprintf(1, "father:%s\n", s);
    if (strcmp("pong", s)) {
      fprintf(1, "%d: received pong\n", getpid());
    }

  } else {
    char *s = "";
    read(p[0], s, 4);
    close(p[0]);
    //    fprintf(1, "child:%s\n", s);
    if (strcmp("ping", s) == 0) {
      fprintf(1, "%d: received ping\n", getpid());
    }
    write(p[1], "pong", 4);
    close(p[1]);
    exit(0);
  }

  exit(0);
}
