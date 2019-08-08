# Sheduling: Multi-level Feedback Queue

## What's MLFQ?

This algorithm tries to solve two kinds of problems:

1. Optimize the turnaround time.
2. In order to bring great interactive experience to the users, it also needs to decrease the response time.

And on this occasion, we don't have any workloads which means the sheduler knows nothing about the jobs: how long they will run, do they need I/O or not, and so on.

So the key of MLFQ is predict the future according to the history. Sounds really magical? In fact, it's just a dynamic mechanism that can change the jobs' running priorities due to each job's running features.

MLFQ is composed with several queues, and these queues have different priorities. When jobs arrive, they will be put into the highest prioty queue(top queue). After the job uses the allocated time in each queue, it will be put into the lower priority queue. And every a period of time, all jobs are put into the top queue again.

## Five rules

1. If A's priority > B's priority, runs A(B's not running).
2. If A's prioity = B's priority, runs A and B in turnaround.
3. When a job arrives, put it into top queue(highest priority).
4. If a job runs out of the allocated time in one level, it will be moved to the lower level.
5. Every period of time S, all jobs will be put into the top queue again.

The advantages of this algorithm is:

1. No need to know a job's foregoing knowledges. Arrange through oberve.
2. Able to fit different kinds of jobs. If a job is interactive and uses short time, the performance is similar to SFJ/STCF. If a job is CPU densely and uses long time, it also can be executed in a fair and stable way.

Many systems use MLFQ as basic shedulers, including BSD UNIX[LM+89,B86], Solaris[M06] and Windows NT alongwith the latter systems.