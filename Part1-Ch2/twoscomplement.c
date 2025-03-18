#include <stdio.h>

typedef unsigned char *byte_pointer;

// Function that prints the raw bytes of memory starting at 'start' for 'len' bytes
// This lets us see how data is actually stored in memory
void show_bytes(byte_pointer start, size_t len) {
  int i;
  // Loop through each byte
  for (i = 0; i < len; i++)
    // Print each byte in hexadecimal format with 2 digits
      // %.2x means: print as hex, use at least 2 digits, pad with zeros if needed
        printf(" %.2x", start[i]);
  printf("\n");
}

int main() {
  short x = 12345; // 0011 1001 0011 0000 // BigEndian 0011 0000 0011 1001
  short mx = -x; // 1100 0110 1100 1111 // BigEndian 1100 1111 1100 0111
  // The two's complement result comes from the equation
  // B2T_w(x) = (x_{w-1}2^{w-1}) + (sum_{i=0}^{w-2} x_i * 2^i)
  // Or, easier to understand:
  // B2T_w(x) = -x[w-1] * 2^(w-1) + sum(x[i] * 2^i for i in range(0, w-2))
  // Alternate representation:
  // B2T_w(x):
  // = -x[w-1] * 2^(w-1)     // Most significant bit is negative
  // + sum(x[i] * 2^i        // Sum of all other bits
  //    for i in range(0, w-2))

  show_bytes((byte_pointer) &x, sizeof(short));
  show_bytes((byte_pointer) &mx, sizeof(short));
  return 0;
}