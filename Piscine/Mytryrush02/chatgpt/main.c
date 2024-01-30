#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define DICT_SIZE 1024

int ft_strlen(const char *str) {
    int len = 0;
    while (str[len])
        len++;
    return len;
}

int ft_strcmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

void ft_putstr(const char *str) {
    write(1, str, ft_strlen(str));
}

char *ft_strdup(const char *str) {
    int len = ft_strlen(str);
    char *new_str = (char *)malloc(len + 1);
    if (!new_str)
        return NULL;
    for (int i = 0; i <= len; i++)
        new_str[i] = str[i];
    return new_str;
}

char *read_dictionary(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1)
        return NULL;

    char *buffer = (char *)malloc(DICT_SIZE);
    if (!buffer)
        return NULL;

    int bytes_read = read(fd, buffer, DICT_SIZE - 1);
    if (bytes_read == -1) {
        free(buffer);
        return NULL;
    }
    buffer[bytes_read] = '\0';

    close(fd);
    return buffer;
}

char *get_value_from_dict(const char *dictionary, const char *key) {
    int idx = 0;
    char *value = NULL;
    
    while (dictionary[idx]) {
        // Find the start of the current entry's key
        int key_start = idx;
        while (dictionary[idx] != ':' && dictionary[idx] != '\0') {
            idx++;
        }
        if (dictionary[idx] == '\0') {
            break; // End of dictionary
        }
        
        // Compare the key with the current entry's key
        if (ft_strcmp(dictionary + key_start, key) == 0) {
            // Move to the value part of the entry
            while (dictionary[idx] != '\0' && dictionary[idx] != ':') {
                idx++;
            }
            if (dictionary[idx] == ':') {
                idx++; // Move past ':'
                while (dictionary[idx] == ' ') {
                    idx++; // Move past spaces
                }
                
                // Extract the value
                int value_start = idx;
                while (dictionary[idx] != '\n' && dictionary[idx] != '\0') {
                    idx++;
                }
                
                int value_length = idx - value_start;
                value = (char *)malloc(value_length + 1);
                if (value) {
                    for (int i = 0; i < value_length; i++) {
                        value[i] = dictionary[value_start + i];
                    }
                    value[value_length] = '\0';
                }
                
                break; // Value extracted
            }
        }

        // Move to the next line
        while (dictionary[idx] != '\n' && dictionary[idx] != '\0') {
            idx++;
        }
        if (dictionary[idx] == '\n') {
            idx++; // Move to the next line
        }
    }
    
    return value;
}

void convert_number_to_words(const char *dictionary, const char *number) {
    int num = atoi(number);

    if (num < 0) {
        ft_putstr("Error\n");
        return;
    }

    if (num == 0) {
        ft_putstr("zero\n");
        return;
    }

    int divisor = 1;
    int count = 0;
    int temp = num;

    // Determine the divisor and count the number of digits
    while (temp > 0) {
        temp /= 10;
        divisor *= 10;
        count++;
    }
    divisor /= 10;

    while (divisor > 0) {
        int digit = num / divisor;
        char digit_str[2];
        digit_str[0] = '0' + digit;
        digit_str[1] = '\0';

        char *value = get_value_from_dict(dictionary, digit_str);
        if (value) {
            ft_putstr(value);
            ft_putstr(" ");
            free(value);
        } else {
            ft_putstr("Dict Error1\n");
            return;
        }

        num %= divisor;
        divisor /= 10;
    }

    ft_putstr("\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3) {
        ft_putstr("Error\n");
        return 1;
    }

    const char *dictionary_filename = "numbers.dict"; // Modify as needed
    char *dictionary = read_dictionary(dictionary_filename);
    if (!dictionary) {
        ft_putstr("Dict Error2\n");
        return 1;
    }

    if (argc == 2) {
        convert_number_to_words(dictionary, argv[1]);
    } else if (argc == 3) {
        convert_number_to_words(dictionary, argv[2]);
    }

    free(dictionary);
    return 0;
}


