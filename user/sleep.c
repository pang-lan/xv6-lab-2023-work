#include "kernel/stat.h"
#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(2, "Please add time\n");
    exit(1);
  }
  int num = atoi(argv[1]);
  sleep(num);
  exit(0);
}
