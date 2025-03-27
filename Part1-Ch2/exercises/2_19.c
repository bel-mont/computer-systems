#include <stdio.h>
#include <inttypes.h>

int main () {
  // Two's complement conversions

  // T2U formula
  // T2Uw (x) = x + 2^w, x < 0
  //            x,       x >= 0

  // word size 4
  printf("\n−1 T2U -> { T2B 1111 }-> { -1 + 2^4 = -1 + 16 = 15 } ");
  printf("\n−5 T2U -> { T2B 1011 }-> { -5 + 2^4 = -5 + 16 = 11 } ");
  printf("\n−6 T2U -> { T2B 1011 }-> { -6 + 2^4 = -6 + 16 = 10 } ");
  printf("\n−4 T2U -> { T2B 0010 }-> { -4 + 2^4 = -4 + 16 = 12 } ");
  printf("\n1 T2U -> { T2B 0111 }-> { 1 } ");
  printf("\n8 T2U -> { T2B 1100 }-> { 8 } ");

  // U2Tw (u) = −u_w-1 * 2^w + u // u_w-1 is the most significant bit
  // Ex with w = 4, and a value of 14
  // 14 = 1110
  // 1 (MSB = 1)
  // So, -1 * 2^4 + 14
  // -1 * 16 + 14
  // -16 + 14
  // -2

  return 0;
}