#pragma once

#include <stdlib.h>
#include <sys/mman.h>

typedef	struct	s_heap {
	struct	s_heap	*xor;
	size_t			total_size;
	size_t			free_size;
	size_t			block_count;
} t_heap;

typedef	struct	s_block {
	struct	s_block	*xor;
	size_t			data_size;
	bool			freed;
} t_block;

#define TINY_HEAP_ALLOCATION_SIZE	(4 * sysconf(_SC_PAGE_SIZE))
#define TINY_BLOCK_SIZE				(TINY_HEAP_ALLOCATION_SIZE / 128)
#define SMALL_HEAP_ALLOCATION_SIZE	(16 * sysconf(_SC_PAGE_SIZE))
#define SMALL_BLOCK_SIZE			(SMALL_HEAP_ALLOCATION_SIZE / 128)

#define	HEAP_SHIFT(start)			((void*)start + sizeof(t_heap))
#define	BLOCK_SHIFT(start)			((void*)start + sizeof(t_block))

void	*heap_list = NULL;

void	free(void *ptr);
void	*malloc(size_t size);
void	*realloc(void *ptr, size_t size);
