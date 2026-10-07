#include "heap.h"

/*
 * print_heap - print the elements currently stored in the heap.
 *
 * heap: pointer to the heap to print. Must not be NULL.
 */
void print_heap(Heap *heap) {
    for (int i = 0; i < (heap->size - heap->capacity); i++) {
        printf("%d ", heap->items[i]);
    }
    putchar('\n');
}

/*
 * heap_init - initialize a heap with a fixed capacity.
 *
 * heap: pointer to an uninitialized Heap struct. Must not be NULL.
 * size: number of elements to allocate space for. Must be > 0.
 *
 * Returns 0 on success.
 * Returns 1 if the internal malloc fails. On failure, heap->size is set
 *         to 0 and heap->items is left undefined (see note).
 */
int heap_init(Heap *heap, int size) {
    heap->items = malloc(sizeof(int) * size);

    if (!heap->items) {
        heap->size = 0;
        return 1;
    }

    heap->size = size;
    heap->capacity = size;
    return 0;
}

/*
 * heap_free - release the heap's backing array and reset its fields.
 *
 * heap: pointer to the heap to free. Must not be NULL.
 */
void heap_free(Heap *heap) {
    free(heap->items);

    heap->items = NULL;
    heap->capacity = 0;
    heap->size = 0;
}

/*
 * heap_push - insert a value into the heap and sift it up.
 *
 * heap:  pointer to an initialized heap. Must not be NULL.
 * value: the integer to insert.
 *
 * Returns 0 on success.
 * Returns 1 if the heap has no free slots (capacity == 0).
 */
int heap_push(Heap *heap, int value) {
    if (heap->capacity == 0) {
        return 1;
    }

    int index = heap->size - heap->capacity;
    heap->items[index] = value;

    int j = index;
    while (j > 0) {
        int parent = (j - 1) / 2;

        if (heap->items[parent] < heap->items[j]) {
            int temp = heap->items[j];
            heap->items[j] = heap->items[parent];
            heap->items[parent] = temp;
        }

        j = parent;
    }

    heap->capacity--;
    return 0;
}

/*
 * heap_pop - remove and return the maximum element from the heap.
 *
 * heap: pointer to an initialized, non-empty heap. Must not be NULL.
 *
 * Returns the maximum element on success.
 * Returns 0 if the heap is empty (capacity == size). Note: 0 is
 *         indistinguishable from a legitimate stored value of 0.
 */
int heap_pop(Heap *heap) {
    if (heap->capacity == heap->size) {
        return 0;
    }

    int top_element = heap->items[0];
    int index = heap->size - heap->capacity - 1;

    heap->items[0] = heap->items[index];

    int j = 0;
    while ((2 * j + 1) < (heap->size - heap->capacity - 1)) {
        int k = 2 * j + 1;

        if ((k + 1 < heap->size) && (heap->items[k] < heap->items[k + 1])) {
            k++;
        }

        if (heap->items[j] < heap->items[k]) {
            int temp = heap->items[k];
            heap->items[k] = heap->items[j];
            heap->items[j] = temp;
        }

        j = k;
    }

    heap->capacity++;
    return top_element;
}
