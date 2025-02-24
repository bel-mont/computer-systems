#include <stdio.h>

void inplace_swap(int* x, int* y)
{
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

void reverse_array(int a[], int cnt)
{
    int first, last;
    for (first = 0, last = cnt - 1;
         first < last;
         first++, last--)
        inplace_swap(&a[first], &a[last]);
}

int main()
{
    // a, b
    int a = 3;
    int b = 5;
    inplace_swap(&a, &b);
    printf("%d %d\n", a, b);

    // Reverse array
    int arr[] = {1, 2, 3, 4};
    reverse_array(arr, 4);
    printf("%d %d %d %d\n", arr[0], arr[1], arr[2], arr[3]);
    // odd length
    int arr2[] = {1, 2, 3, 4, 5};
    reverse_array(arr2, 5);
    printf("%d %d %d %d %d\n", arr2[0], arr2[1], arr2[2], arr2[3], arr2[4]);
    return 0;
}
