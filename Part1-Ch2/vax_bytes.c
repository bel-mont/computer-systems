/* Declarations of functions implementing operations bis and bic */
/*  sets x to 1 at each bit position where m is 1*/
int bis(int x, int m);
/*  sets x to 0 at each bit position where m is 1*/
int bic(int x, int m);
/* Compute x|y using only calls to functions bis and bic */
int bool_or(int x, int y) {
    int result = bis(x, y);
    return result;
}
/* 2.13 Compute x^y using only calls to functions bis and bic */
int bool_xor(int x, int y) {
    int result = bis(bic(x, y), bic(y, x));

    // x ^ y = (x & ~y) | (~x & y)
    // Example with x = 0x7 (0111), y = 0x2 (0010)
    // (0111 & ~0010) | (~0111 & 0010)
    // (0111 & 1101) | (1000 & 0010)
    // 0101 | 0000
    // 0101
    // 0x5
    return result;
}