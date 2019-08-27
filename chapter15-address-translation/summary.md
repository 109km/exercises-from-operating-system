# Mechanism: Address Translation

## Introduction

The crux of virtualizing memory efficiently and flexibly is **hardware-based address translation**. With address translation, the hardware transforms each memory access, changing the virtual address provided by the instruaction to a physical address where the desired information is actually located.

The hardware just provides the low-level mechanism. The OS must get involved at key points to set up the hardware so that the correct translations take place, it must keep track of which locations are free and which are in use, and judiciously intervening to maintain control over how memory is used.

A program in virtual view is like below: the first part is program code, follows by heap, and the bottom part is stack.

![memory-translation.jpg](./memory-translation.jpg)


A program in hardware view is like this:

the real memory of the program is relocated, it's different from virtual address.

![memory-in-os.jpg](./memory-in-os.jpg)

## Dynamic(Hardware-based) relocation

There are two hardware registers within each CPU:
* Base register. Record a process' start address in physical memory.
* Bound register. This register has two implementations: it can be the size of the address space or the end of the phsysical address space. 

A equation: 

```
Physical address = virtual address + base address
```

The steps of a virtual address being converted to a physical address is quite simple: 

1. Check the virtual address in inside the bounds, the bounds register stores the virtual address not the physical address.
2. Plus the virtual address and base address(physical address) to get the final physical address.