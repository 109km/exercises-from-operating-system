# Lottery Sheduling

## Basic concepts: tickets = proportion

`ticket` stands for a process' proportion of some resources. 

For an example, if there're two processes A and B, we hope A uses 75% of CPU's time, and B uses 25% of CPU's time, we can treat this situation in the lottery way: there're 100 tickets in total, A has 75 tickets, B has 25 tickets. Then the sheduler decides which process to run through lottery drawing.

## Lottery mechanism

The lottery sheduling support some different ways to shudule the tickets:

1. Ticket currency. Assume user A and B have 100 tickets in total. User A has two jobs A1 and A2, he can allot his own currency to each job, like he has 1000 A-tickets and allot 500 to each job. User B has only one job, he has 10 B-tickets and allot 10 to the one job. It means each process can decide how to arrange their own jobs.
2. Ticket transfer. A process can transfer its tickets to another process. This mechanism is often very useful in Client-Server case, when a client sends messages to the server, it always hope the server can response as quickly as possible, so the client can transfer its tickets to the server to speed up the server's execution.
3. Ticket inflation. Sometimes a process can increase or decrease its tickets. But in the competing environment, procesess don't trust each other, a greedy process may increase its tickets to a large number to take over the machine. On the other hand in a trusted enviroment, this mechanism is useful.

## Implementation

The lottery sheduling's implementation is very simple, it needs only 3 things: a nice random number maker, a list that records all processes' data structure, total number of tickets.

```
head -> Job A(Tix:100) -> Job B(Tix:50) -> Job C(Tix:250) -> NULL
```
If the winner number is 300, the program starts to loop each job and add their tickets, when current number >= 300, the winner job is found.

## How to allot ticets?

A system's execution depends on tickets' allocation. So how to allocate the tickets to each job? If an user knows how to allocate the tickets to its own jobs, the system can give some tickets to it, but what if it doesn't know?

Until now, there's not a perfect solution.

## Why using random : another implementation

The random way's flawness is if a job's running time is short, the unfairness metric can be large.

So if each job has a `stride`, this number is inverse proportion to the number of tickets. If A/B/C's tickets are 100/50/250, we use a big number like 10000 divide them, got their strides are 100/200/40. When a process is executed, its stride will be increased, and the `pass` will be increased too. After that, the sheduler decides which process to run according to the stride and pass.

This implementation's advantage is fair and accurate, can assure all processes' progresses are very near. But if a new job comes into the system, how to set its pass? If set it to 0, this job will monopolize the CPU.

So the lottery sheduling can treat all jobs in a relative fair way.

But in reality, both implementations are not used.