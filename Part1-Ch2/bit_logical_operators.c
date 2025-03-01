#include <stdio.h>

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

  return 0;
}