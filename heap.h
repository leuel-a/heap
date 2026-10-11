#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct Heap - structure for the Heap DSA
 *
 * @size: size of the heap
 * @capacity: the current capacity of the heap
 * @items: the items that are stored in the heap
 */
typedef struct Heap
{
	int size;
	int capacity;
	int *items;
} Heap;

void print_heap(Heap *heap);
int heap_init(Heap *heap, int size);
void heap_free(Heap *heap);
int heap_push(Heap *heap, int value);
int heap_pop(Heap *heap);

#endif
