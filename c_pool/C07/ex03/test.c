#include <stdio.h>
#include <string.h>
#include "ft_strjoin.c"

int main() {
    int tests_passed = 0;
    int tests_total = 0;

    // Test 1
    {
        char *strs[] = {"Hello", "world!"};
        char *sep = ", ";
        char *expected = "Hello, world!";
        
        char *result = ft_strjoin(2, strs, sep);
        printf("%s\n", result);
        if (strcmp(result, expected) == 0) {
            printf("Test 1 passed\n");
            tests_passed++;
        } else {
            printf("Test 1 failed\n");
        }
        
        free(result);
        tests_total++;
    }

    // Test 2
    {
        char *strs[] = {"This", "is", "a", "test"};
        char *sep = "-";
        char *expected = "This-is-a-test";
        
        char *result = ft_strjoin(4, strs, sep);
        printf("%s\n", result);
        if (strcmp(result, expected) == 0) {
            printf("Test 2 passed\n");
            tests_passed++;
        } else {
            printf("Test 2 failed\n");
        }
        
        free(result);
        tests_total++;
    }

    // Ajoutez d'autres tests ici...

    printf("Tests passed: %d / %d\n", tests_passed, tests_total);

    return 0;
}


