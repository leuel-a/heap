#include "heap.h"

void print_heap(Heap *heap) {
    for (int i = 0; i < (heap->size - heap->capacity); i++) {
        printf("%d ", heap->items[i]);
    }
    putchar('\n');
}

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

void heap_free(Heap *heap) {
    free(heap->items);

    heap->items = NULL;
    heap->capacity = 0;
    heap->size = 0;
}

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

int heap_pop(Heap *heap) {
    if (heap->capacity == heap->size) {
        return 0;
    }

    int top_element = heap->items[0];
    int index = heap->size - heap->capacity - 1;

    heap->items[0] = heap->items[index];

    int j = 0;
    while ((2 * j + 1) < heap->size) {
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
