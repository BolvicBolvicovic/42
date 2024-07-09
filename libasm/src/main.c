#include "../inc/libasm.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>

int main() {

	char	*len = "hello";
	assert(ft_strlen(len) == strlen(len));
	printf("\e[0;32mft_strlen: Success\n\e[0;31m");
	
	char	cpy[50];
	char	*res = ft_strcpy(cpy, len);
	assert(strcmp(len, cpy) == 0);
	assert(res == cpy);
	printf("\e[0;32mft_strcpy: Success\n\e[0;31m");
	
	assert(strcmp(len, cpy) == ft_strcmp(len, cpy));
//	assert(strcmp("hey", "hoe") == ft_strcmp("hey", "hoe"));
	assert(strcmp("hey", "hoe") < 0);
	assert(ft_strcmp("hey", "hoe") < 0);
	printf("\e[0;32mft_strcmp: Success\n\e[0;31m");
	return 0;
}
