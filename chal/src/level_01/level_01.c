#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
  puts("Nice, du har kørt mit program!\nHer er dit flag:");

  FILE *file = fopen("/home/pirat/level_01/flag", "r");

  if (file) {
    char c;
    while ((c = getc(file)) != EOF) putchar(c);
    fclose(file);
  }

  return 0;
}
