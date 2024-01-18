#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Prototype de la fonction custom ft_strdup
char *ft_strdup(const char *src);

int main() {
    // Test 1: Chaîne vide
    const char *empty_str = "";
    char *result_empty = ft_strdup(empty_str);
    printf("Test 1: \n'%s' \n'%s'\n", empty_str, result_empty);
    free(result_empty);

    // Test 2: Chaîne non vide
    const char *original_str = "Hello, world!";
    char *result = ft_strdup(original_str);
    printf("Test 2: \n'%s' \n'%s'\n", original_str, result);
    free(result);

    // Test 3: Chaîne avec caractères spéciaux
    const char *special_chars = "Testing \t special \n characters";
    char *result_special = ft_strdup(special_chars);
    printf("Test 3: \n'%s' \n'%s'\n", special_chars, result_special);
    free(result_special);

    // Test 4: Chaîne très longue
    const char *long_str = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";
    char *result_long = ft_strdup(long_str);
    printf("Test 4: \n'%s' \n'%s'\n", long_str, result_long);
    free(result_long);

    // Test 5: Chaîne contenant un caractère nul
    const char *null_char_str = "This string\0contains a null character";
    char *result_null = ft_strdup(null_char_str);
    printf("Test 5: \n'%s' \n'%s'\n", null_char_str, result_null);
    free(result_null);

    return 0;
}

