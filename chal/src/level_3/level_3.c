#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
  if (argc < 1) {
    puts("An unexpected error occurred!");
    return 1;
  }

  if (argv[0][0] != '/') {
    printf("Forkert :/.\nDu startede programmet med %s.\nDu skal bruge en absolut sti istedet.\n", argv[0]);
    return 1;
  }

  puts("Godt lavet, her er et flag:");

  FILE *file = fopen("/home/pirat/level_3/flag", "r");

  if (file) {
    char c;
    while ((c = getc(file)) != EOF) putchar(c);
    fclose(file);
  }

  return 0;
}
