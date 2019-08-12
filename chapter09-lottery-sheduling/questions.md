### 1. Get the solutions of 3 jobs when random seed is 1/2/3.

```
Random seed = 1

ARG jlist 
ARG jobs 3
ARG maxlen 10
ARG maxticket 100
ARG quantum 1
ARG seed 1

Here is the job list, with the run time of each job: 
  Job 0 ( length = 1, tickets = 84 )
  Job 1 ( length = 7, tickets = 25 )
  Job 2 ( length = 4, tickets = 44 )

** Solutions **
Random 651593 -> Winning ticket 119 (of 153) -> Run 2
  Jobs:
 (  job:0 timeleft:1 tix:84 ) 
 (  job:1 timeleft:7 tix:25 ) 
 (* job:2 timeleft:4 tix:44 ) 

Random 788724 -> Winning ticket 9 (of 153) -> Run 0
  Jobs:
 (* job:0 timeleft:1 tix:84 ) 
 (  job:1 timeleft:7 tix:25 ) 
 (  job:2 timeleft:3 tix:44 ) 

--> JOB 0 DONE at time 2
Random 93859 -> Winning ticket 19 (of 69) -> Run 1
  Jobs:
 (  job:0 timeleft:0 tix:--- ) 
 (* job:1 timeleft:7 tix:25 ) 
 (  job:2 timeleft:3 tix:44 ) 

Random 28347 -> Winning ticket 57 (of 69) -> Run 2
  Jobs:
 (  job:0 timeleft:0 tix:--- ) 
 (  job:1 timeleft:6 tix:25 ) 
 (* job:2 timeleft:3 tix:44 ) 

Random 835765 -> Winning ticket 37 (of 69) -> Run 2
  Jobs:
 (  job:0 timeleft:0 tix:--- ) 
 (  job:1 timeleft:6 tix:25 ) 
 (* job:2 timeleft:2 tix:44 ) 

Random 432767 -> Winning ticket 68 (of 69) -> Run 2
  Jobs:
 (  job:0 timeleft:0 tix:--- ) 
 (  job:1 timeleft:6 tix:25 ) 
 (* job:2 timeleft:1 tix:44 ) 

--> JOB 2 DONE at time 6
Random 762280 -> Winning ticket 5 (of 25) -> Run 1
  Jobs:
 (  job:0 timeleft:0 tix:--- ) 
 (* job:1 timeleft:6 tix:25 ) 
 (  job:2 timeleft:0 tix:--- ) 

Random 2106 -> Winning ticket 6 (of 25) -> Run 1
  Jobs:
 (  job:0 timeleft:0 tix:--- ) 
 (* job:1 timeleft:5 tix:25 ) 
 (  job:2 timeleft:0 tix:--- ) 

Random 445387 -> Winning ticket 12 (of 25) -> Run 1
  Jobs:
 (  job:0 timeleft:0 tix:--- ) 
 (* job:1 timeleft:4 tix:25 ) 
 (  job:2 timeleft:0 tix:--- ) 

Random 721540 -> Winning ticket 15 (of 25) -> Run 1
  Jobs:
 (  job:0 timeleft:0 tix:--- ) 
 (* job:1 timeleft:3 tix:25 ) 
 (  job:2 timeleft:0 tix:--- ) 

Random 228762 -> Winning ticket 12 (of 25) -> Run 1
  Jobs:
 (  job:0 timeleft:0 tix:--- ) 
 (* job:1 timeleft:2 tix:25 ) 
 (  job:2 timeleft:0 tix:--- ) 

Random 945271 -> Winning ticket 21 (of 25) -> Run 1
  Jobs:
 (  job:0 timeleft:0 tix:--- ) 
 (* job:1 timeleft:1 tix:25 ) 
 (  job:2 timeleft:0 tix:--- ) 

--> JOB 1 DONE at time 12

```

### 2. If there are two jobs, each length is 10, Job 0 has 1 ticket, and Job 1 has 100 tickets. Before Job 1 finished, Job 0 can run or not?

There is possibility, but it's quite small. When the tickets are not allocated fairly, some jobs may monopolize the CPU.

```
ARG jlist 10:1,10:100
ARG jobs 3
ARG maxlen 10
ARG maxticket 100
ARG quantum 1
ARG seed 0

Here is the job list, with the run time of each job: 
  Job 0 ( length = 10, tickets = 1 )
  Job 1 ( length = 10, tickets = 100 )


** Solutions **

Random 844422 -> Winning ticket 62 (of 101) -> Run 1
  Jobs:
 (  job:0 timeleft:10 tix:1 ) 
 (* job:1 timeleft:10 tix:100 ) 

Random 757955 -> Winning ticket 51 (of 101) -> Run 1
  Jobs:
 (  job:0 timeleft:10 tix:1 ) 
 (* job:1 timeleft:9 tix:100 ) 

Random 420572 -> Winning ticket 8 (of 101) -> Run 1
  Jobs:
 (  job:0 timeleft:10 tix:1 ) 
 (* job:1 timeleft:8 tix:100 ) 

Random 258917 -> Winning ticket 54 (of 101) -> Run 1
  Jobs:
 (  job:0 timeleft:10 tix:1 ) 
 (* job:1 timeleft:7 tix:100 ) 

Random 511275 -> Winning ticket 13 (of 101) -> Run 1
  Jobs:
 (  job:0 timeleft:10 tix:1 ) 
 (* job:1 timeleft:6 tix:100 ) 

Random 404934 -> Winning ticket 25 (of 101) -> Run 1
  Jobs:
 (  job:0 timeleft:10 tix:1 ) 
 (* job:1 timeleft:5 tix:100 ) 

Random 783799 -> Winning ticket 39 (of 101) -> Run 1
  Jobs:
 (  job:0 timeleft:10 tix:1 ) 
 (* job:1 timeleft:4 tix:100 ) 

Random 303313 -> Winning ticket 10 (of 101) -> Run 1
  Jobs:
 (  job:0 timeleft:10 tix:1 ) 
 (* job:1 timeleft:3 tix:100 ) 

Random 476597 -> Winning ticket 79 (of 101) -> Run 1
  Jobs:
 (  job:0 timeleft:10 tix:1 ) 
 (* job:1 timeleft:2 tix:100 ) 

Random 583382 -> Winning ticket 6 (of 101) -> Run 1
  Jobs:
 (  job:0 timeleft:10 tix:1 ) 
 (* job:1 timeleft:1 tix:100 ) 

--> JOB 1 DONE at time 10
Random 908113 -> Winning ticket 0 (of 1) -> Run 0
  Jobs:
 (* job:0 timeleft:10 tix:1 ) 
 (  job:1 timeleft:0 tix:--- ) 

Random 504687 -> Winning ticket 0 (of 1) -> Run 0
  Jobs:
 (* job:0 timeleft:9 tix:1 ) 
 (  job:1 timeleft:0 tix:--- ) 

Random 281838 -> Winning ticket 0 (of 1) -> Run 0
  Jobs:
 (* job:0 timeleft:8 tix:1 ) 
 (  job:1 timeleft:0 tix:--- ) 

Random 755804 -> Winning ticket 0 (of 1) -> Run 0
  Jobs:
 (* job:0 timeleft:7 tix:1 ) 
 (  job:1 timeleft:0 tix:--- ) 

Random 618369 -> Winning ticket 0 (of 1) -> Run 0
  Jobs:
 (* job:0 timeleft:6 tix:1 ) 
 (  job:1 timeleft:0 tix:--- ) 

Random 250506 -> Winning ticket 0 (of 1) -> Run 0
  Jobs:
 (* job:0 timeleft:5 tix:1 ) 
 (  job:1 timeleft:0 tix:--- ) 

Random 909747 -> Winning ticket 0 (of 1) -> Run 0
  Jobs:
 (* job:0 timeleft:4 tix:1 ) 
 (  job:1 timeleft:0 tix:--- ) 

Random 982786 -> Winning ticket 0 (of 1) -> Run 0
  Jobs:
 (* job:0 timeleft:3 tix:1 ) 
 (  job:1 timeleft:0 tix:--- ) 

Random 810218 -> Winning ticket 0 (of 1) -> Run 0
  Jobs:
 (* job:0 timeleft:2 tix:1 ) 
 (  job:1 timeleft:0 tix:--- ) 

Random 902166 -> Winning ticket 0 (of 1) -> Run 0
  Jobs:
 (* job:0 timeleft:1 tix:1 ) 
 (  job:1 timeleft:0 tix:--- ) 

--> JOB 0 DONE at time 20
```

### 3. Two jobs: both lengths are 100 and have 100 tickets, how unfair the sheduler is?

Run command below:

`python3 lottery.py -s 2 -l 100:100,100:100 -c  `

From the answer below, we can see once the two jobs' leftTime's gap is becoming larger, the more unfair the sheduler is.

```
Random 511501 -> Winning ticket 101 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:10 tix:100 ) 
 (* job:1 timeleft:1 tix:100 ) 

--> JOB 1 DONE at time 190
Random 581076 -> Winning ticket 76 (of 100) -> Run 0
  Jobs:
 (* job:0 timeleft:10 tix:100 ) 
 (  job:1 timeleft:0 tix:--- ) 

Random 51234 -> Winning ticket 34 (of 100) -> Run 0
  Jobs:
 (* job:0 timeleft:9 tix:100 ) 
 (  job:1 timeleft:0 tix:--- ) 

Random 418016 -> Winning ticket 16 (of 100) -> Run 0
  Jobs:
 (* job:0 timeleft:8 tix:100 ) 
 (  job:1 timeleft:0 tix:--- ) 

Random 525065 -> Winning ticket 65 (of 100) -> Run 0
  Jobs:
 (* job:0 timeleft:7 tix:100 ) 
 (  job:1 timeleft:0 tix:--- ) 

Random 181225 -> Winning ticket 25 (of 100) -> Run 0
  Jobs:
 (* job:0 timeleft:6 tix:100 ) 
 (  job:1 timeleft:0 tix:--- ) 

Random 93786 -> Winning ticket 86 (of 100) -> Run 0
  Jobs:
 (* job:0 timeleft:5 tix:100 ) 
 (  job:1 timeleft:0 tix:--- ) 

Random 802656 -> Winning ticket 56 (of 100) -> Run 0
  Jobs:
 (* job:0 timeleft:4 tix:100 ) 
 (  job:1 timeleft:0 tix:--- ) 

Random 366184 -> Winning ticket 84 (of 100) -> Run 0
  Jobs:
 (* job:0 timeleft:3 tix:100 ) 
 (  job:1 timeleft:0 tix:--- ) 

Random 519210 -> Winning ticket 10 (of 100) -> Run 0
  Jobs:
 (* job:0 timeleft:2 tix:100 ) 
 (  job:1 timeleft:0 tix:--- ) 

Random 921451 -> Winning ticket 51 (of 100) -> Run 0
  Jobs:
 (* job:0 timeleft:1 tix:100 ) 
 (  job:1 timeleft:0 tix:--- ) 
```

### Q4. What happens if quantum becomes larger?

The unfairness may become larger.