#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char flagbuf[256];

const char charset[] = "abcdefghijklmnopqrstuvwxyz_";

int main(int argc, char **argv) {
  srandom(1337);

  FILE *file = fopen("/home/${LINUX_USERNAME}/level_09/flag", "r");
  if ((!file) || (!fgets(flagbuf, sizeof(flagbuf), file))) {
    fprintf(stderr, "Kunne ikke læse flaget.\n");
    return 1;
  }
  fclose(file);

  int flagline = 500 + random() % 337;
  int line;
  int linelen;
  for (line=1;line<flagline;line++) {
    for (linelen=0; linelen<60; linelen++) {
      putchar(charset[random() % 27]);
    }
    putchar('\n');
  }
  printf("rltxqocbqdhmpo_%sbdqqjptzgwuquyx\n", flagbuf);
  for (;line<1337;line++) {
    for (linelen=0; linelen<60; linelen++) {
      putchar(charset[random() % 27]);
    }
    putchar('\n');
  }

  return 0;
}
