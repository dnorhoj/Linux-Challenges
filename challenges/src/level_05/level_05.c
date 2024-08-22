#include <libgen.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {
  char filebuf[256];
  int len;

  len = readlink("/proc/self/fd/1", filebuf, sizeof(filebuf) - 1);
  if (len == -1) {
    fprintf(stderr, "Der skete en fejl (burde ikke ske)\n");
    return 1;
  }

  filebuf[len] = 0x00;

  if (filebuf[0] != '/' || isatty(1)) {
    fprintf(stderr, "Du skal redirecte outputtet til en fil!\n");
    return 1;
  }

  char *filename = basename(filebuf);

  if (strcmp(filename, "helloworld") != 0) {
    fprintf(stderr,
            "Du har redirected outputtet til en fil der hedder '%s'.\n"
            "Du skal redirecte det til en fil der hedder helloworld.\n",
            filename);
    return 1;
  }

  FILE *file = fopen("/home/${LINUX_USERNAME}/level_05/flag", "r");

  if (file) {
    char c;
    while ((c = getc(file)) != EOF) putchar(c);
    fclose(file);
  }

  fprintf(stderr, "Nice! Det er rigtigt. Jeg har lagt flaget i filen ;)\n");

  return 0;
}
