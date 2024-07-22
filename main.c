#include <stdint.h>
#include <stdio.h>

#include "xoshiro256starstar.c"

int main(int argc, char **argv) {
  for (--argc, ++argv; argc > 0; --argc, ++argv) {
    s[0] = 'S';
    s[1] = 'E';
    s[2] = 'E';
    s[3] = 'D';
    for (char *ip = *argv; *ip; ++ip) {
      switch(*ip) {
        case 'j': {
          jump();
          break;
        }
        case 'l': {
          long_jump();
          break;
        }
        case 'n': {
          next();
          break;
        }
        case 'c': {
          s[1] = 0;
          s[2] = 0;
          s[3] = 0;
          break;
        }
        case 'x': {
          s[0] = ~s[0];
          s[1] = ~s[1];
          s[2] = ~s[2];
          s[3] = ~s[3];
          break;
        }
        case 's': {
          uint64_t s0 = s[0];
          s[0] = s[1];
          s[1] = s0;
          uint64_t s2 = s[2];
          s[2] = s[3];
          s[3] = s2;
          break;
        }
        case '0': {
          s[0]++;
          break;
        }
        case '1': {
          s[1]++;
          break;
        }
        case '2': {
          s[2]++;
          break;
        }
        case '3': {
          s[3]++;
          break;
        }
      }
      printf("%c: %016llx %016llx %016llx %016llx\n", *ip, s[0], s[1], s[2], s[3]);
    }
    printf("\n");
  }
  
  return 0;
}
