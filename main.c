#include "heap.h"

int main() {
    Heap heap;
    int size = 10;

    if (heap_init(&heap, size) != 0) {
        printf("Something went wrong while allocating heap!!");
        return 0;
    }

    heap_push(&heap, 10);
    heap_push(&heap, 8);
    heap_push(&heap, 7);
    heap_push(&heap, 4);

    print_heap(&heap);

    heap_pop(&heap);

    print_heap(&heap);
    return 0;
}
