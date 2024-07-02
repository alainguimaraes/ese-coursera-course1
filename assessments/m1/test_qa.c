#include <stdio.h>
#include <assert.h>
#include <math.h>

#include "stats.h"
#define SIZE (40)
void test_print_statistics() {
    unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                                114, 88,   45,  76, 123,  87,  25,  23,
                                200, 122, 150, 90,   92,  87, 177, 244,
                                201,   6,  12,  60,   8,   2,   5,  67,
                                  7,  87, 250, 230,  99,   3, 100,  90};

    printf("Running test_print_statistics...\n");

    print_statistics(test, SIZE);

    assert(find_minimum(test, SIZE) == 2);
    assert(find_minimum_index(test, SIZE) == 6);
    assert(find_maximum(test, SIZE) == 250);
    assert(find_maximum_index(test, SIZE) == 35);
    assert(find_mean(test, SIZE) == 94);
    assert(find_median(test, SIZE) == 87);
    assert(find_median_index(test, SIZE) == 20);

    printf("test_print_statistics passed!\n");
}

void test_print_array() {
    unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                                114, 88,   45,  76, 123,  87,  25,  23,
                                200, 122, 150, 90,   92,  87, 177, 244,
                                201,   6,  12,  60,   8,   2,   5,  67,
                                  7,  87, 250, 230,  99,   3, 100,  90};

    printf("Running test_print_array...\n");

    print_array(test, SIZE);
    // No assertion here, just visually inspect the output

    printf("test_print_array passed!\n");
}

void test_sort_array() {
    unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                                114, 88,   45,  76, 123,  87,  25,  23,
                                200, 122, 150, 90,   92,  87, 177, 244,
                                201,   6,  12,  60,   8,   2,   5,  67,
                                  7,  87, 250, 230,  99,   3, 100,  90};

    printf("Running test_sort_array...\n");

    sort_array(test, SIZE);

    for (int i = 0; i < SIZE - 1; i++) {
        assert(test[i] <= test[i + 1]);
    }

    printf("test_sort_array passed!\n");
}

int main() {
    test_print_statistics();
    test_print_array();
    test_sort_array();
    return 0;
}
