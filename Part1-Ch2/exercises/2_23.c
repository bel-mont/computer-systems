#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
  int i;
  for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);
  printf("\n");
}

int fun1(unsigned word) {
    return (int) ((word << 24) >> 24);
}
int fun2(unsigned word) {
    return ((int) word << 24) >> 24;
}

int main () {
  // Explanation
  short sx = -12345; /* -12345 */
  unsigned uy = sx; /* Mystery! */
  // Two's complement signed to unsigned quirk
  // short sx = -12345; /* -12345 */
  // unsigned uy = sx; /* 4,294,954,951 */
  // 1100 0111 1100 0111  (-12345 in 16-bit two’s complement)
  // 1111 1111 1111 1111 1100 0111 1100 0111  (-12345 in 32-bit two’s complement)
  // C will first expand the most significant bit to convert to the new word size of 32
  // After that, it will convert to unsigned
  // Keeping the same bits changes the value to 4,294,954,951

  printf("uy = %u:\t", uy);
  show_bytes((byte_pointer) &uy, sizeof(unsigned));
  // Sign extension happens before converting to unsigned. This order is required by the C standard.
  // Cast first if a different behavior is needed.

  // right shifts of signed values are performed arithmetically (copies MSB)
  // right shifts of unsigned values are performed logically (adds 0s)
  // 0x00000076 (118)
  // fun1(U) int
    // -> 00 00 00 76 (unsigned)
    // -> (76 00 00 00)
    // -> (00 00 00 76) // add 0s with logical shift
    // -> 0111 0110 -> 64 + 32 + 16 + 4 + 2 -> 118
  // fun2(U) int
    // -> 00 00 00 76 (signed int)
    // -> (76 00 00 00)
    // -> (00 00 00 76) // 7 is 0111, the MSB is 0, and is used when shifting right on signed
    // -> 0111 0110 -> 64 + 32 + 16 + 4 + 2 -> 118

  // 0x87654321
  // fun1(U) int
    // -> 87 65 43 21 (unsigned)
    // -> 21 00 00 00
    // -> 00 00 00 21 // add 0s with logical shift
    // -> 0010 0001 -> 32 + 1 = 33
  // fun2(U) int
    // -> 87 65 43 21 (signed int)
    // -> 21 00 00 00
    // -> 00 00 00 21 // 7 is 0111, the MSB is 0, and is used when shifting right on signed
    // -> 0010 0001 -> 32 + 1 = 33

  // 0x000000C9
  // fun1(U) int
    // 00 00 00 C9 (unsigned)
    // C9 00 00 00
    // 00 00 00 C9 // add 0s with logical shift
    // 1100 1001 -> 128 + 64 + 8 + 1 = 201
  // fun2(U) int
    // 00 00 00 C9 (signed int)
    // C9 00 00 00
    // FF FF FF C9 // C is 1100, MSB is 1, so we shift with 1
    // 11...11 1100 1001 -> -2,147,483,648 + 2,147,483,392 (sum of all bit values) + 128 + 64 + 8 + 1 = -55

  // 0xEDCBA987
  // fun1(U) int
    // ED CB A9 87 (unsigned)
    // 87 00 00 00
    // 00 00 00 87 // add 0s with logical shift
    // 1000 0111 -> 128 + 8 + 4 + 1 = 141
  // fun2(U) int
    // ED CB A9 87 (signed int)
    // 87 00 00 00
    // FF FF FF 87 // 8 is 1000, MSB is 1, so we shift with 1
    // 11...11 1000 0111 -> -2,147,483,648 + 2,147,483,392 (sum of all bit values == -256) + 128 + 64 + 8 + 1 = -115

  // Function fun1 extracts a value from the low-order 8 bits of the argument,
  // giving an integer ranging between 0 and 255. Function fun2 extracts a value
  // from the low-order 8 bits of the argument, but it also performs sign extension.
  // The result will be a number between −128 and 127.
  // Note that actually executing the function will have different behavior depending
  // on what type of shift operation the host computer does (logical vs arithmetical)
  return 0;
}