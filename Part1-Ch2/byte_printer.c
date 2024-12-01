//
// Created by cidhi on 12/1/2024.
//

#include <stdio.h>

// Define a new type 'byte_pointer' that is a pointer to an unsigned char
// This allows us to examine memory one byte at a time
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

// Function to show how an integer is stored in memory
void show_int(int x) {
    // &x gets the address where x is stored
    // (byte_pointer) casts this address to our byte_pointer type
    // sizeof(int) tells us how many bytes to print (usually 4 on modern systems)
    show_bytes((byte_pointer) &x, sizeof(int));
}

// Function to show how a float is stored in memory
// Floats use a different format (IEEE 754) than integers
void show_float(float x) {
    // Similar to show_int, but for float data type
    show_bytes((byte_pointer) &x, sizeof(float));
}

// Function to show how a pointer is stored in memory
// On 32-bit systems, pointers are 4 bytes
// On 64-bit systems, pointers are 8 bytes
void show_pointer(void *x) {
    // Note: we take the address of x (&x) because we want to see how
    // the pointer itself is stored, not what it points to
    show_bytes((byte_pointer) &x, sizeof(void *));
}

// Demonstrates type conversions and their byte representations
void test_show_bytes(int val) {
    // Create three different representations of the same value
    int ival = val;                  // Keep as integer
    float fval = (float) ival;       // Convert to float
    int *pval = &ival;               // Create pointer to the integer

    printf("For input value: %d\n", val);
    printf("Integer representation:\n");
    show_int(ival);
    printf("Float representation:\n");
    show_float(fval);
    printf("Pointer representation:\n");
    show_pointer(pval);
}

int main() {
    // Set up some test values
    int test_int = 12345;            // A regular integer
    float test_float = 12345.0;      // Same number as a float
    int *test_ptr = &test_int;       // A pointer to our test_int

    printf("Demonstrating byte representations:\n");

    // Show how 12345 is stored as an integer
    // This will show the actual bytes used to represent the number
    printf("Integer 12345:\n");
    show_int(test_int);

    // Show how 12345.0 is stored as a float
    // This will look different from the integer because it uses IEEE 754 format
    printf("Float 12345.0:\n");
    show_float(test_float);

    // Show how the pointer is stored
    // This will show the memory address where test_int lives
    printf("Pointer to test_int:\n");
    show_pointer(test_ptr);

    printf("\n=== Conversion Tests ===\n");
    // Test with different values to see how they're represented
    printf("\nTesting with 12345:\n");
    test_show_bytes(12345);

    printf("\nTesting with negative value -12345:\n");
    test_show_bytes(-12345);

    printf("\nTesting with zero:\n");
    test_show_bytes(0);
    return 0;
}