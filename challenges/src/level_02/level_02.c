#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {
  if (argc > 2) {
    printf("Du har skrevet '");
    for (int i = 1; i < argc; i++) {
      printf("%s", argv[i]);

      if (i != argc - 1) {
        printf(" ");
      }
    }
    printf("', men du skulle bare skrive ostemad!\n");
    return 1;
  } else if (argc < 2) {
    puts("Du har ikke givet programmet noget argument!");
    puts("Læs README.md for at se hvad du skal gøre (cat README.md)");
    return 1;
  } else if (strcmp("ostemad", argv[1]) != 0) {
    printf("Hov, du har skrevet '%s', men du skulle have skrevet ostemad!\n",
           argv[1]);
    return 1;
  }

  puts("Det er helt rigtigt! Her er et flag til dig:");

  FILE *file = fopen("/home/pirat/level_02/flag", "r");

  if (file) {
    char c;
    while ((c = getc(file)) != EOF) putchar(c);
    fclose(file);
  }

  return 0;
}
