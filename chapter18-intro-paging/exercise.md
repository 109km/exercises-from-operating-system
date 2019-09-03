## Question

```
ARG seed 0
ARG address space size 16k
ARG phys mem size 64k
ARG page size 4k
ARG verbose False

The format of the page table is simple:
The high-order (left-most) bit is the VALID bit.
  If the bit is 1, the rest of the entry is the PFN.
  If the bit is 0, the page is not valid.
Use verbose mode (-v) if you want to print the VPN # by
each entry of the page table.

Page Table (from entry 0 down to the max size)
   0x0000000c
   0x00000000
   0x00000000
   0x00000006

Virtual Address Trace
  VA  0: 0x00003229 (decimal:    12841) --> PA or invalid? 
  VA  1: 0x00001369 (decimal:     4969) --> PA or invalid?
  VA  2: 0x00001e80 (decimal:     7808) --> PA or invalid?
  VA  3: 0x00002556 (decimal:     9558) --> PA or invalid?
  VA  4: 0x00003a1e (decimal:    14878) --> PA or invalid?
```

**Answer**

Page size = 4k, so each VA has 14 bits, 2 bits for VPN and 12 bits for offset.

The first VA is 0x3229 = 11 0010 0010 1001, so its VPN = 3, offset = 0x229

The VPN 3 is 0x6, so its first bit is 1. So it's a valid page. And combine the page number and the offset: PA = 0x6229.

VA1 = 4969 = 01 0011 0110 1001, so its VPN = 1, offset = 0x369, the second page's first bit is 0, so it's invalid.

VA 2 = 7808 = 01 1110 1000 0000, its VPN = 1, this page is invalid.

VA 3 = 9558 = 10 0101 0101 0110, its VPN = 2, this page is also invalid.

VA 4 = 14878 = 11 1010 0001 1110, its VPN = 3, this page is valid, and the offset = 0xa1e, so the PA = 0x6a1e


