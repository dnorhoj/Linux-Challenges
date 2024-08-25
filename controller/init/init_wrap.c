#include <stdlib.h>
#include <unistd.h>

int main() {
  setuid(0);
  system("/usr/bin/init.sh");
  return 0;
}