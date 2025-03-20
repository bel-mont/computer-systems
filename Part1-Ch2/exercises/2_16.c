#include <stdio.h>

/* Problem 2.16*/
int main () {
  const int a = 0xD4;
  printf("%08x: 1101 0100\n", a);

  // a << 2
  printf("%d << 2 bin %02x: 0101 0000\n", a, a << 2);
  printf("%d << 2 hex %02x: 0x50\n", a, a << 2);

  // logical >> 3
  printf("%d >> 3 bin %02x: 0001 1010\n", a, a >> 3);
  printf("%d << 3 hex %02x: 0x1A\n", a, a >> 3);

  // NOTE: almost all compiler/machine combinations use arithmetic right shifts for signed data
  // Arithmetic >> 3 ()
  printf("%d >> 3 arith bin %02x: 1111 1010\n", a, a >> 3);
  printf("%d >> 3 arith hex %02x: 0xFA\n", a, a >> 3);


  const int b = 0x64;
  printf("%08x: 0110 0100\n", b);

  // b << 2
  printf("%d << 2 bin %02x: 1001 0000\n", b, b << 2);
  printf("%d << 2 hex %02x: 0x90\n", b, b << 2);

  // logical >> 3
  printf("%d >> 3 bin %02x: 0000 1100\n", b, b >> 3);
  printf("%d << 3 hex %02x: 0x0C\n", b, b >> 3);

  // NOTE: almost all compiler/machine combinations use arithmetic right shifts for signed data
  // Arithmetic >> 3 ()
  printf("%d >> 3 arith bin %02x: 0110 0100\n", b, b >> 3);
  printf("%d >> 3 arith hex %02x: 0x0C\n", b, b >> 3); // The book's answer is EC, check

  const int c = 0x72;
  printf("%08x: 0111 0010\n", c);

  // b << 2
  printf("%d << 2 bin %02x: 1100 1000\n", c, c << 2);
  printf("%d << 2 hex %02x: 0xC8\n", c, c << 2);

  // logical >> 3
  printf("%d >> 3 bin %02x: 0000 1110\n", c, c >> 3);
  printf("%d << 3 hex %02x: 0x0E\n", c, c >> 3);

  // NOTE: almost all compiler/machine combinations use arithmetic right shifts for signed data
  // Arithmetic >> 3 ()
  printf("%d >> 3 arith bin %02x: 0000 1110\n", c, c >> 3);
  printf("%d >> 3 arith hex %02x: 0x0E\n", c, c >> 3);

  const int d = 0x44;
  printf("%08x: 0100 0100\n", d);

  // b << 2
  printf("%d << 2 bin %02x: 0001 0000\n", d, d << 2);
  printf("%d << 2 hex %02x: 0x10\n", d, d << 2);

  // logical >> 3
  printf("%d >> 3 bin %02x: 0000 1000\n", d, d >> 3);
  printf("%d << 3 hex %02x: 0x08\n", d, d >> 3);

  // NOTE: almost all compiler/machine combinations use arithmetic right shifts for signed data
  // Arithmetic >> 3 ()
  printf("%d >> 3 arith bin %02x: 0000 1000\n", d, d >> 3);
  printf("%d >> 3 arith hex %02x: 0x08\n", d, d >> 3); // The book's answer is E9, check

  return 0;
}