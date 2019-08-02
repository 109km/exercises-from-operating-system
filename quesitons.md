### Q1: Use SJF and FIFO algorithms to run 3 jobs which length is 200, calculte their turnaround time and response time.

In this case, the two algorithms are the same.

```
T(turnaround) = (200 + 400 + 600) / 3 = 400
T(response) = (0 + 200 + 400) / 3 = 200
```

### Q2: Do the same thing, but jobs' lengths are different: 100,200,300

```
SJF
T(turnaround) = (100 + 300 + 600) / 3 = 333.33
T(response) = (0 + 100 + 300) / 3 = 133.33

FIFO
In this case, it depends on the jobs' order. If the order is 100->200->300, the result is the same with SJF's, on the other hand, the results are quite different. Assume order is 200->300->100:
T(turnaround) = (200 + 500 + 600) / 3 = 433.33
T(response) = (0 + 200 + 500) / 3 = 233.33
```
### Q3: Do the same thing, use RR algorithm, and time slice is 1.

```
If the 3 jobs arrive at the same time:
T(turnaround) = (598 + 599 + 600) / 3 ≈ 599
T(response) = (0 + 1 + 2) / 3 = 1 
```

### Q4: To what kind of workload, the SJF and FIFO have the same turnaround time?

The jobs order is from shortest to longest.

### Q5: To what kind of workload and time slice, the SJF and RR have the same response time?