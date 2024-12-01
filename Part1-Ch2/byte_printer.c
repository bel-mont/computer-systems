//
// Created by cidhi on 12/1/2024.
//

#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    int i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}

int main() {
    int test_int = 12345;
    float test_float = 12345.0;
    int *test_ptr = &test_int;

    printf("Demonstrating byte representations:\n");

    printf("Integer 12345:\n");
    show_int(test_int);

    printf("Float 12345.0:\n");
    show_float(test_float);

    printf("Pointer to test_int:\n");
    show_pointer(test_ptr);

    return 0;
}