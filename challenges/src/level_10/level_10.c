#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

char flagbuf[256];

const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

// Robert Jenkins' 96 bit Mix Function
unsigned long mix(unsigned long a, unsigned long b, unsigned long c)
{
    a=a-b;  a=a-c;  a=a^(c >> 13);
    b=b-c;  b=b-a;  b=b^(a << 8);
    c=c-a;  c=c-b;  c=c^(b >> 13);
    a=a-b;  a=a-c;  a=a^(c >> 12);
    b=b-c;  b=b-a;  b=b^(a << 16);
    c=c-a;  c=c-b;  c=c^(b >> 5);
    a=a-b;  a=a-c;  a=a^(c >> 3);
    b=b-c;  b=b-a;  b=b^(a << 10);
    c=c-a;  c=c-b;  c=c^(b >> 15);
    return c;
}

int main(int argc, char **argv) {
  srandom((int)mix(clock(), time(NULL), getpid()));

  FILE *file = fopen("/home/pirat/level_10/flag", "r");
  if ((!file) || (!fgets(flagbuf, sizeof(flagbuf), file))) {
    fprintf(stderr, "Kunne ikke læse flaget.\n");
    return 1;
  }
  fclose(file);

  int flagline = 200 + random() % 937;
  int line;
  int linelen;
  for (line=1;line<flagline;line++) {
    for (linelen=0; linelen<48; linelen++) {
      putchar(charset[random() % 64]);
    }
    putchar('\n');
  }
  printf("%s\n", flagbuf);
  for (;line<1337;line++) {
    for (linelen=0; linelen<48; linelen++) {
      putchar(charset[random() % 64]);
    }
    putchar('\n');
  }

  return 0;
}
