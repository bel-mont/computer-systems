#include <stdio.h>

int main () {
  // Using a word size of 4.
  printf("0xA: Binary 1010, B2U: 10 (8+2), B2T: -6 (-8+2)");
  printf("0x1: Binary 0001, B2U: 1 (1), B2T: 1 (1)");
  printf("0xB: Binary 1011, B2U: 11 (8+2+1), B2T: -5 (-8+2+1)");
  printf("0x2: Binary 0010, B2U: 2 (2), B2T: 2 (2)");
  printf("0x7: Binary 0111, B2U: 7 (4+2+1), B2T: 7 (4+2+1)");
  printf("0xC: Binary 1100, B2U: 12 (8+4), B2T: -4 (-8+4)");
  return 0;
}