# Heap

A small, fixed-capacity **max-heap** of `int`s, implemented in C.

## Build and run

```sh
gcc -Wall -Wextra -g main.c heap.c -o heap
./heap
```

## API

| Function                              | Description                                                                 |
| ------------------------------------- | --------------------------------------------------------------------------- |
| `int heap_init(Heap *h, int size)`    | Allocates room for `size` items. Returns `0` on success, `1` on failure.    |
| `int heap_push(Heap *h, int value)`   | Inserts `value`. Returns `0` on success, `1` if the heap is full.           |
| `int heap_pop(Heap *h)`               | Removes and returns the largest value. Returns `0` if the heap is empty.    |
| `void print_heap(Heap *h)`            | Prints the backing array in level order, for debugging.                     |
| `void heap_free(Heap *h)`             | Frees the backing array and resets the struct.                              |

## Example

```c
#include "heap.h"

int main(void) {
    Heap heap;

    if (heap_init(&heap, 10) != 0) {
        fprintf(stderr, "Failed to allocate heap\n");
        return 1;
    }

    heap_push(&heap, 10);
    heap_push(&heap, 8);
    heap_push(&heap, 7);
    heap_push(&heap, 4);

    print_heap(&heap);              // 10 8 7 4

    int top = heap_pop(&heap);      // 10
    printf("popped: %d\n", top);

    print_heap(&heap);              // 8 4 7

    heap_free(&heap);
    return 0;
}
```

## Limitations

- Capacity is fixed at `heap_init`; the heap does not grow.
- Stores `int` only, and is a max-heap only.
- `heap_pop` returns `0` on an empty heap, which is indistinguishable from
  popping a real `0`.
