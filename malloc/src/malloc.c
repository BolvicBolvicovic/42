#include "../inc/libft_malloc.h"

void	*malloc(size_t size) {
	if (!size) { return NULL; }
	void	*buffer = NULL;
	if (!heap_list) {
		heap_list = (t_heap *)mmap(
								NULL,
								size,
								PROT_READ | PROT_WRITE,
								MAP_PRIVATE | MAP_ANON,
								-1,
								0
		);
	}

	return	buffer;
}
