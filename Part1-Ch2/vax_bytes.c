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
    return result;
}