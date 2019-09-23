# Summary Of Memory Virtualization

## Abstraction Address(Virtual Address)

All the addresses that allocated by the OS are abstraction addresses. 

There's a translating relation between the abstraction address and physical address.

## Virtualizing techs for memory

Most of the modern x86 CPUs have an MMU(memory management unit) and a TLB(Translation-lookaside buffer).


### Segmentation

OS splits the memory that the process need into three parts : Code, Stack, Heap. So that each process's memory doesn't need to continuous. 

### Paging

OS splits the whole memory into many small pages, like many cells in a cupboard, when a process needs memory, the OS allocates some 'cells'(`pages`) to this process.

### TLB

TLB is the cache for pages, it's a hardware in the CPU. When the CPU tries to find an address, it will search this address in TLB.

If hit, the CPU gets the result immediately. 

If not, a TLB miss processing flow will begin.

In this way, the speed of visiting addresses is much faster.

### Mechanisms of beyond physical memory 

Swapping the pages from memory to disk can make the memory seems bigger.

The important thing is the differences between `mechanism` and `policy`.


### Policies

Some concrete algorithms for swapping the pages. They use the concepts and functions provided by `mechanism`.

