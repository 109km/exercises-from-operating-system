# Interlude: Memory API

## Types of memory

* Stack memory. Its allocations and deallocations are managed implicitly by the compiler for you. In C program, the variables declared in functions are managed by the compiler, they are in the stack memory.
* Heap memory. All the allocations and deallocations are managed by the programmers. In C program, the `malloc` api is for users to allocate memory manually, and users can deallocate memory with the api `free`.