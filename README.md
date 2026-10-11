# Heap

A small, fixed-capacity **max-heap** of `int`s, implemented in C. To build and run use:

```sh
gcc -Wall -Wextra -g main.c heap.c -o heap
./heap
```

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
