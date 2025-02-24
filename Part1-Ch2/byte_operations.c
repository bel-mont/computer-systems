#include <stdio.h>

void inplace_swap(int *x, int *y) {
  *y = *x ^ *y; /* Step 1, 0110 = 0011 ^ 0101 */
  *x = *x ^ *y; /* Step 2, 0101 = 0011 ^ 0110 */
  *y = *x ^ *y; /* Step 3, 00 11 = 0101 ^ 0110 */
  // STEP    x     y
  // Init    a     b
  // Step 1, (a), (a^b)
  // Step 2, (a ^ (a^b)) = (a^a) ^ b = b, a ^ b
  // Step 3, b,   b ^ (a ^ b) = (b ^ b) ^ a = a
  // The above flow uses "a" and "b" as a substitute for any constants
  // that are assigned to x and y.
}

int main() {
  // a, b
  int a = 3;
  int b = 5;
  inplace_swap(&a, &b);
  printf("%d %d\n", a, b);
  return 0;
}
