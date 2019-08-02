# Introduction to sheduling

## What is CPU sheduling ?

* The allocation of processors to process over time.
* Key to multiprogramming.
* Increase CPU utiliztion and job throughput by overlapping I/O and computation.
* Different queues representing different process states(ready,running,block)
* Policies: if there are more than one processes, how to choose which one to run next?

## Workload assumptions

Before we try to find the possible policies, we need to make some simple assumptions so that the policies won't be quite complex.

Here is the assumptions:

1. Each job runs the same amount of time.
2. All jobs arrive at the same time.
3. Once a job started, it runs to completion.
4. All jobs only use the CPU(no I/O).
5. Each job's running time is known.

Some of these assumptions are not realisitc, and we will relax them gradually to see how it works in a real system.

## Sheduling Metric 1 : Turnaround Time

```
T(turnaround) = T(completion) - T(arrive)
```

## Algorithm 1 : FIFO(First In First Out)

`FIFO` also means first come first serve, the jobs are executed in the order of their arrival time.

Let's see an example. Assume there are 3 jobs(A,B,C) arrive at the same time, FIFO must decide what are their orders. We assume A is a little earlier than B, and B is a little earlier than C, and each job's runnning time is 10s.

The average T(turnaround) of these jobs is (10 + 20 + 30) / 3 = 20. Assume anther case, if job A's running time is 100s, this policy will work badly, in this case the average T(turnaround) is (100 + 110 + 120) / 3 = 110. Is it terrible?

So this algorithm's biggest defect is if the earlier jobs' running time is long, the whole system will become really slow.

## Algorithm 2 : SJF(Shortest Job First)

Now let's relax the first and second assumptions.

In this algorithm, the shorter jobs are executed earlierly. So let's review last example, B and C take 10s to run, and A takes 100s, now the running order will become B->C->A, in this case the average T(turnaround) is (10 + 20 + 120) / 3 = 50. It's a big progress.

But what if B and C arrive after A, assume they arrive after A runned 10s? The average T(turnaround) is (100 + 100 + 110) / 3 = 103.3. Again, the policy works quite slow in this case.

## Algorithm 3 : STCF(Shortest Time-to-Completion First)

We'll relax the third assumption here.

Let's look back the example in algorithm 2, so when B and C arrive after A runned 10s, the sheduler can decide to stop A, because B and C have shorter runnning time, so the execution order will be like this:

 ```flowchart
  A(10s)->B(10s)->C(10s)->A(90s)
 ```
Now the average T(turnaround) = (10 + 20 + 120) / 3 = 50

We can see that in this situation this algorithm is pretty good.

## Sheduling Metric 2 : Response Time

```
T(response) = T(first run) - T(arrive)
```

In the example above, the average response time is:

```
T(response of A) = 0 - 0 = 0
T(response of B) = 20 - 20 = 0
T(response of C) = 20 - 10 = 10
average T(response) =  (0 + 0 + 10) / 3 = 6.66
```

## Algorithm 4 : Round-Robin

In a `time slice`, the CPU works on one task, then switch to the next task in the queue. Each job can be splitted into many tasks. Each task's smallest time is `time slice`.

For example, if the `time slice` is 1s, A B and C are 10s' jobs. And no matter what their arrive time is, the response time will be quit short. Assume that A and B arrive at the same time, C arrives after 3s.

```
A(1s)->B(1s)->A(1s)->C(1s)->B(1s)...
```
Now the average T(response) is (0 + 1 + 1) / 3 = 0.66. To this algrithm the longest waiting time could be one `time slice`.

So how do we set a proper `time slice` ? If it's too short, context switching will affect the whole performance. It's easy to understand: if one `time slice` takes 1s, and context switching takes 0.1s, the radio is 10%, if one `time slice` takes 10s, the radio is 1%.

The system designer must balance the length of `time slice`, make it long enough to amortize the context switching cost, and won't make the response time too slow in the meanwhile.

Now we've got two metrics: turnaround time and response time. If we chase only one of them, SJF and STCF are pretty good for turnaround time, RR is great for response time. But now we still have two assumptions which are not relaxed.

## Combine with I/O

Now let's relax the assumption 4: all jobs may need I/O and when they are using I/O, they won't use CPU.

There are 2 jobs: A(50ms) arrives at 0 and needs IO, B(50ms) arrives at 10ms and neednt' IO.

Now what's the best plan?

The timing graph will be like blow:

```
CPU: |A(10ms)|B(10ms)|A(10ms)|B(10ms)|A(10ms)|....
IO:  |-------|A(10ms)|-------|A(10ms)|-------|....
```

This method is called `overlap` the CPU doesn't wait, it will always be running. This is a great idea for multiple jobs.

## Unpredictable

What happens if we relax the assumption 5? All the algorithms above won't work any more. But we can think about how to optimize the algorithms so that they can work with assumption 5, or even combine some algorithms together?

## Summary

We introduced the basic thinking of sheduling, and developed two kinds of algorithms: friendly to turnaround time and friendly to response time. But it's still hard to get the two metrics done together.

Now we still don't know how to solve the unseen problems in the future.
