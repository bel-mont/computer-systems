#include <stdio.h>

int equals(int x, int y)
{
  // Using bit operators and logical operators, return 1 when x and y are true
  // return 0 otherwise
  const int result = !(x ^ y);
  printf("x & y %08x\n", result);
  return result;
}

int main() {
  const int a = 0x55;
  const int b = 0x46;

  printf("a & b %08x\n", a & b);
  printf("a | b %08x\n", a | b);
  printf("~a | ~b %08x\n", ~a | ~b);
  printf("a & !b %08x\n", a & !b);

  printf("a && b %08x\n", a && b);
  printf("a || b %08x\n", a || b);
  printf("!a || !b %08x\n", !a || !b);
  printf("a && ~b %08x\n", a && ~b);

  printf("Equals 50 == 40: %d\n", equals(50, 40));
  printf("Equals 45 == 45: %d\n", equals(45, 45));
  printf("Equals 2 == 1: %d\n", equals(2, 1));
  printf("Equals 2 == 2: %d\n", equals(2, 2));
  printf("Equals 24123 == 7182: %d\n", equals(24123, 7182));
  printf("Equals 24123 == 24123: %d\n", equals(24123, 24123));

  const int x = 0x7;
  const int y = 0x2;
  printf("7 ^ 2: %08x\n", (x & ~y) | (~x & y));

  return 0;
}