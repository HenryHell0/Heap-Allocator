#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <stddef.h> // Include the header file for NULL
#include <sys/mman.h> // Include the header file for mmap

#include "block.h"

// initial size of the memory pool
#define INITIAL_POOL_SIZE 4096

Block *initialize_allocator(size_t size);
Block *allocate_more(size_t size);

#endif
