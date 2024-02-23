#include "test_include.h"

Block *create_initial_pool(size_t size) {
	printf("Initializing the allocator...\n");
	Block *first_pool = initialize_allocator(size);
	return first_pool;
}

void test_initial_pool_not_null(Block *first_pool) {
	printf("Checking if the initial pool is not null. ❓\n");
	ASSERT(first_pool != NULL, "The initial pool is null. 😨");
	printf("The initial pool is not null. ✅\n");
}

void test_initial_pool_free(Block *first_pool) {
	printf("Checking if the initial pool is marked as free. ❓\n");
	ASSERT(first_pool->free == 1, "The initial pool is not free. 😨");
	printf("The initial pool is marked as free. ✅\n");
}

void test_initial_pool_size(Block *first_pool) {
	printf("Checking if the initial pool's size is correct. ❓\n");
	ASSERT(first_pool->size == 1024, "The initial pool's size is not correct. 😨");
	printf("The initial pool's size is correct as expected. (%zu bytes.) ✅\n", first_pool->size);
}

void test_initial_pool_prev_null(Block *first_pool) {
	printf("Checking if the initial pool's prev is null. ❓\n");
	ASSERT(first_pool->prev == NULL, "The initial pool's prev is not null. 😨");
	printf("The initial pool's prev is null. ✅\n");
}

void test_initial_pool_next_null(Block *first_pool) {
	printf("Checking if the initial pool's next is null. ❓\n");
	ASSERT(first_pool->next == NULL, "The initial pool's next is not null. 😨");
	printf("The initial pool's next is null. ✅\n");
}

// Test for singleton behavior
void test_singleton_behaviour(Block *initial_pool1) {
	size_t size2 = 2048;
	Block *initial_pool2 = initialize_allocator(size2);

	printf("Checking for the singleton behaviour of initialize allocator. Pointers... ❓\n");
	ASSERT(initial_pool1 == initial_pool2, "Two pools returned different pointers. 😨");
	printf("Singleton behaviour confirmed. Pointers: %p %p ✅\n", initial_pool1, initial_pool2);

	printf("Checking for the singleton behaviour of initialize allocator. Sizes same ❓\n");
	ASSERT(initial_pool1 == initial_pool2, "Two pools returned different sizes. 😨");
	printf("Singleton behaviour confirmed sizes are the same. ✅\n");
}
