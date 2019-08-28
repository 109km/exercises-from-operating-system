## Q1. `python3 malloc.py -S 100 -b 1000 -H 4 -a 4 -l ADDRSORT -p BEST -n 5`

```
ptr[0] = Alloc(3)  returned ?
List? 

------1000
header
------1004
allocated
------1008


Free(ptr[0]) returned ?
List?

ptr[1] = Alloc(5)  returned ?
List?

Free(ptr[1]) returned ?
List?

ptr[2] = Alloc(8)  returned ?
List?
```
Result:
```
seed 0
size 100
baseAddr 1000
headerSize 4
alignment 4
policy BEST
listOrder ADDRSORT
coalesce False
numOps 5
range 10
percentAlloc 50
allocList 
compute True

ptr[0] = Alloc(3)
 returned 1004 (searched 1 elements)
Free List [ Size 1 ]: 
[ addr:1008 sz:92 ]


Free(ptr[0])
returned 0
Free List [ Size 2 ]: 
[ addr:1000 sz:8 ]
[ addr:1008 sz:92 ]


ptr[1] = Alloc(5)
 returned 1012 (searched 2 elements)

1012 + 8

Free List [ Size 2 ]: 
[ addr:1000 sz:8 ]
[ addr:1020 sz:80 ]


Free(ptr[1])
returned 0
Free List [ Size 3 ]: 
[ addr:1000 sz:8 ]
[ addr:1008 sz:12 ]
[ addr:1020 sz:80 ]


ptr[2] = Alloc(8)
 returned 1012 (searched 3 elements)
Free List [ Size 2 ]: 
[ addr:1000 sz:8 ]
[ addr:1020 sz:80 ]
```