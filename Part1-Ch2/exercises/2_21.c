#include <stdio.h>

int main () {

  printf(" -2147483647-1 == 2147483648U, type: unsigned, evaluation: 1 (2147483649 - 1 == 2147483648U)");
  // 1000 0000 (times 6) 0001, subtract -1 -> 1000 0000 (times 7)
  printf(" -2147483647-1 < 2147483647, type: signed, evaluation: 1 (-2147483648 < 2147483647)");
  // 1000 0000 (times 6) 0001 -> unsigned becomes 2,147,483,649, which is larger than 2,147,483,647
  printf(" -2147483647-1U < 2147483647, type: unsigned, evaluation: 0 (2147483649 - 1 < 2147483647)");
  printf(" -2147483647-1 < -2147483647, type: signed, evaluation: 1 (-2147483648 < -2147483647)");
  printf(" -2147483647-1U < -2147483647, type: unsigned, evaluation: 1 (2147483649 -1 < 2147483649)");
  return 0;
}
