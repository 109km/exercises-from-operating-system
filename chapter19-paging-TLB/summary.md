# Paging: Faster Translations(TLBs)

## Background

The traditional page talbes are very slow, so `TLB` is created to increase the page tables visiting speed. Actually it's a kind of cache. It's also a hardware inside the CPU, it stores some page tables' data.

**Remember the key of computer's world is another level of abstraction**

## How the CPU acess data from memory? 

![memory-visit-progress.jpg](./memory-visit-progress.jpg)