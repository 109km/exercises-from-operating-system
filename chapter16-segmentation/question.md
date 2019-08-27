## Q1.
```
ARG seed 10
ARG address space size 1k
ARG phys mem size 16k

Segment register information:

  Segment 0 base  (grows positive) : 0x000024ff (decimal 9471)
  Segment 0 limit                  : 402

  Segment 1 base  (grows negative) : 0x00000e9d (decimal 3741)
  Segment 1 limit                  : 365

Virtual Address Trace
  VA  0: 0x00000340 (decimal:  832) --> PA or segmentation violation?
  VA  1: 0x0000034b (decimal:  843) --> PA or segmentation violation?
  VA  2: 0x0000029d (decimal:  669) --> PA or segmentation violation?
  VA  3: 0x000000a4 (decimal:  164) --> PA or segmentation violation?

For each virtual address, either write down the physical address it translates to
OR write down that it is an out-of-bounds address (a segmentation violation). For
this problem, you should assume a simple address space with two segments: the top
bit of the virtual address can thus be used to check whether the virtual address
is in segment 0 (topbit=0) or segment 1 (topbit=1). Note that the base/limit pairs
given to you grow in different directions, depending on the segment, i.e., segment 0
grows in the positive direction, whereas segment 1 in the negative. 
```

Answer:

```
  VA  0: 0x00000340 (decimal:  832) --> 1101000000 --> Seg1 offset = 320 - 511 = -191,PA = 3741 - 191 = 3550
  VA  1: 0x0000034b (decimal:  843) --> 1101001011 --> Seg1 offset = 331 - 511 = -180, PA = 3741 - 180 = 3561
  VA  2: 0x0000029d (decimal:  669) --> 1010011101 --> Seg1
  offset = 157 - 511 = -354, PA = 3741 - 354 = 3387
  VA  3: 0x000000a4 (decimal:  164) --> 010100100 --> Seg0
  offset = 164, PA = 9471 + 164 = 9635
```


## Q2.

```
ARG seed 0
ARG address space size 1k
ARG phys mem size 16k

Segment register information:

  Segment 0 base  (grows positive) : 0x00001aea (decimal 6890)
  Segment 0 limit                  : 472

  Segment 1 base  (grows negative) : 0x00001254 (decimal 4692)
  Segment 1 limit                  : 450

Virtual Address Trace
  VA  0: 0x0000020b (decimal:  523) --> PA or segmentation violation?
  VA  1: 0x0000019e (decimal:  414) --> PA or segmentation violation?
  VA  2: 0x00000322 (decimal:  802) --> PA or segmentation violation?
  VA  3: 0x00000136 (decimal:  310) --> PA or segmentation violation?
  VA  4: 0x000001e8 (decimal:  488) --> PA or segmentation violation?

For each virtual address, either write down the physical address it translates to
OR write down that it is an out-of-bounds address (a segmentation violation). For
this problem, you should assume a simple address space with two segments: the top
bit of the virtual address can thus be used to check whether the virtual address
is in segment 0 (topbit=0) or segment 1 (topbit=1). Note that the base/limit pairs
given to you grow in different directions, depending on the segment, i.e., segment 0
grows in the positive direction, whereas segment 1 in the negative. 
```

Answer:

```
VA0: 523 -> 10 0000 1011 -> SEG1,offset=11, negative offset = 11 - 511 = -500, |-500| > 450, Segmentation fault.
VA1: 414 -> 01 1001 1110 -> SEG0, offset=414, PA = 6890 + 414 = 7304
VA2: 802 -> 11 0010 0010 -> SEG1, offset=290-511=-221, PA = 4692 - 221 = 4471
VA3: 310 -> 01 0011 0110 -> SEG0, offset=310, PA = 6890 + 310 = 7200
VA4: 488 -> 01 1110 1000 -> SEG0, offset=488 > limit(472), Segmentation fault.
```