#include <stdio.h>
#include <stdlib.h>

int *ft_range(int min, int max);

void test_ft_range(int min, int max) {
    int *result = ft_range(min, max);
    int size = max - min;

    printf("Testing ft_range(%d, %d):\n", min, max);
    if (result == NULL) {
        printf("Returned pointer is NULL. Test failed.\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        if (result[i] != min + i) {
            printf("Mismatch at index %d. Expected: %d, Got: %d\n", i, min + i, result[i]);
            free(result);
            return;
        }
    }

    printf("Test passed.\n");
    free(result);
}

int main() {
    // Test cases
    test_ft_range(0, 5);    // Test with positive range
    test_ft_range(-5, 0);   // Test with negative range
    test_ft_range(10, 20);  // Test with a larger range
    test_ft_range(0, 0);    // Test with zero range

    return 0;
}

