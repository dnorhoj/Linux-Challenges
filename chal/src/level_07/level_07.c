#include <libgen.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {
  char stdin_pathbuf[256];

  if (isatty(STDIN_FILENO)) {
    fprintf(stderr, "Hov, du har ikke redirectet en fil ind i stdin.\n");
    return 1;
  }

  ssize_t linklen =
      readlink("/proc/self/fd/0", stdin_pathbuf, sizeof(stdin_pathbuf) - 1);

  if (linklen == -1) {
    fprintf(stderr, "Der skete en fejl (burde ikke ske)\n");
    return 1;
  }

  stdin_pathbuf[linklen] = 0x00;

  char *stdin_filename = basename(stdin_pathbuf);

  if (strncmp(stdin_filename, "pipe:[", sizeof("pipe:[") - 1) == 0) {
    fprintf(stderr, "Hov, det er en kommand. Du skal bruge '<'.\n");
    return 1;
  }

  if (strcmp(stdin_filename, "coding") != 0) {
    fprintf(stderr, "Hov, din fil hedder '%s', og ikke 'coding'!\n",
            stdin_filename);
    return 1;
  }

  char contents_buf[16];

  size_t len = fread(contents_buf, 1, sizeof(contents_buf) - 1, stdin);
  contents_buf[len] = 0x00;

  if (strncmp(contents_buf, "pirates", sizeof("pirates") - 1) != 0 ||
      (contents_buf[sizeof("pirates") - 1] != 0x00 &&
       contents_buf[sizeof("pirates") - 1] != 0x0a)) {
    fprintf(stderr, "Der står ikke 'pirates' i filen.\n");
    return 1;
  }

  puts("Let's gooo. Her er flaget:");

  FILE *file = fopen("/home/pirat/level_07/flag", "r");

  if (file) {
    char c;
    while ((c = getc(file)) != EOF) putchar(c);
    fclose(file);
  }

  return 0;
}