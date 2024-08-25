#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {
  if (argc > 2) {
    printf("Du har givet %d argumenter, men du skal kun give 1.\n", argc - 1);
    return 1;
  } else if (argc < 2) {
    puts("Du har ikke givet en kode.");
    return 1;
  }

  if (strncmp("JlayYM6lwOyjuab2SawTot6IDNBeIUXni6a8Z5FeKQ8", argv[1], 44) != 0) {
    puts("Forkert kode! Prøv at læse manualen ;)");
    return 1;
  }

  puts("Det var den rigtige kode!");

  FILE *file = fopen("/home/${LINUX_USERNAME}/level_04/flag", "r");

  if (file) {
    char c;
    while ((c = getc(file)) != EOF) putchar(c);
    fclose(file);
  }

  return 0;
}
