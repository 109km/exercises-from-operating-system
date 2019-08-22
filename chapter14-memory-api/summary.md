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

* Forgetting To Allocate Memory.

The wrong way:
```c
char *src = "hello";
char *dst; // oops! unallocated
strcpy(dst, src); // segfault and die
```
The right way:
```c
char *src = "hello";
char *dst = (char *) malloc(strlen(src) + 1);
strcpy(dst, src); // work properly
```

* Not Allocating Enough Memory

```c
char *src = "hello";
char *dst = (char *) malloc(strlen(src)); // too small! The length need to + 1.
strcpy(dst, src); // work properly
```

* Forgetting to Initialize Allocated Memory. Called `malloc()`, but no values are filled.
* Forgetting To Free Memory. Forgeted to `free()` the allocated memory.
* Freeing Memory Before You Are Done With It. This can cause memory leak.
* Freeing Memory Repeatedly. Free the memory more than once.
* Calling free() Incorrectly: only receives the pointers returned from `malloc`, if the pointer is from other ways, bad things will happen.





