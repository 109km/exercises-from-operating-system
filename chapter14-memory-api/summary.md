# Interlude: Memory API

## Types of memory

* Stack memory. Its allocations and deallocations are managed implicitly by the compiler for you. In C program, the variables declared in functions are managed by the compiler, they are in the stack memory.
* Heap memory. All the allocations and deallocations are managed by the programmers. In C program, the `malloc` api is for users to allocate memory manually, and users can deallocate memory with the api `free`.
  
## The `malloc()` call

This API takes only one parameter: the size of bytes. It returns a pointer to the address allocated.

```c
#include <stdlib.h>
void *malloc(size_t size);
```


## The `free()` call

This API deallocates the memory allocated by `malloc`.
```c
free(void *address)
```

## Common Errors

When using `malloc()` and `free()` some common errors.

1. Forgetting To Allocate Memory: 
2. Not Allocating Enough Memory
3. Forgetting to Initialize Allocated Memory
4. Forgetting To Free Memory
5. Freeing Memory Before You Are Done With It
6. Freeing Memory Repeatedly
7. Calling free() Incorrectly: only receives the pointers returned from `malloc`, if the pointer is from other ways, bad things will happen.





