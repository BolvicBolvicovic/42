#include <stdio.h>
#include <stdlib.h>
#include "ft_ultimate_range.c"

void print_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int *range;
    int size;

    printf("Test 1: min >= max\n");
    size = ft_ultimate_range(&range, 10, 5);
    printf("Expected: range is NULL, size is 0\n");
    printf("Returned: range is %p, size is %d\n", (void *)range, size);
    free(range);

    printf("\nTest 2: Valid range\n");
    size = ft_ultimate_range(&range, 5, 10);
    printf("Expected: range is [5 6 7 8 9], size is 5\n");
    printf("Returned: range is ");
    print_array(range, size);
    printf("Returned size: %d\n", size);
    free(range);

    printf("\nTest 3: Negative range\n");
    size = ft_ultimate_range(&range, -5, 0);
    printf("Expected: range is [-5 -4 -3 -2 -1], size is 5\n");
    printf("Returned: range is ");
    print_array(range, size);
    printf("Returned size: %d\n", size);
    free(range);

    return 0;
}
