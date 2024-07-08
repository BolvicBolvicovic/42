#include "../inc/libasm.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>

int main() {

	char	*len = "hello";
	assert(ft_strlen(len) == strlen(len));
	printf("\e[0;32mft_strlen: Success\n");

	return 0;
}
