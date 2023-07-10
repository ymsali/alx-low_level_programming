#include "main.h"
#include <stdlib.h>

/**
 * _realloc - reallocates a memory block.
 * @ptr: pointer to the memory previously allocated.
 * @old_size: size, in bytes, of the allocated space of ptr.
 * @new_size: new size, in bytes, of the new memory block.
 *
 * Return: Pointer to the reallocated memory block.
 * If new_size == old_size, returns ptr without changes.
 * If malloc fails or new_size is 0 and ptr is not NULL, returns NULL.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return NULL;
	}

	if (ptr == NULL)
		return malloc(new_size);

	if (new_size == old_size)
		return ptr;

	void *new_ptr = malloc(new_size);

	if (new_ptr == NULL)
		return NULL;

	// Copy the contents of the old memory block to the new memory block
	unsigned int copy_size = (new_size < old_size) ? new_size : old_size;
	char *src = ptr;
	char *dest = new_ptr;

	for (unsigned int i = 0; i < copy_size; i++)
		dest[i] = src[i];

	free(ptr);

	return new_ptr;
}

