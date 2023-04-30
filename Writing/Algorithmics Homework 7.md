# Algorithmics Homework 7
###### tags: `report` `algorithm`
```
第 7 組
資工二B 109502546 劉語芯
資工二B 109502549 徐瑄琳
資工二B 109502550 許筱敏
資工二B 109502551 葉容瑄
資工二B 109502564 林奕辰
資管二A 109403020 王廷傑
```

### Problem 1
Show how to use property 2 of Lemma 16.12 to determine in time $O(|A|)$ whether or not a given set $A$ of tasks is independent.


**Lemma 16.12**
For any set of tasks $A$, the following statements are equivalent.
1. The set $A$ is independent.
2. For $t = 0, 1, 2, \cdots , n$, we have $N_t(A) \le t$.
3. If the tasks in $A$ are scheduled in order of monotonically increasing deadlines, then no task is late.
- For $t = 0, 1, 2, ..., n$, let $N_t(A)$ denote the **number of tasks** in $A$ whose deadline is $t$ or earlier. Note that $N_0(A) = 0$ for any set $A$.

- `d[i]` denotes the deadline of task `i`
- `n` denotes the number of tasks in set $A$
- `N[t]` denotes the number of tasks in $A$ such that `d[i]` $\le$ `t`

#### pseudocode
```
is_independent(d[])
    n = d.size
    N[n] = {0} // initialize
    for i = 1 to n:
        if (d[i] <= n) N[d[i]]++
    for t = 1 to n:
        N[t] += N[t-1]
        if (N[t] > t) return false
    return true
```
- Time Complexity : $O(n)$

### Problem 2

Suppose you are given a set $S$ = { a~1~, a~2~, ... , a~n~ } of tasks, where task $a_i$ requires $p_i$ units of processing time to complete, once it has started. You have one computer on which to run these tasks, and the computer can run only one task at a time. Let $c_i$ be the completion time of task $a_i$, that is, the time at which task $a_i$ completes processing. Your goal is to minimize the average completion time, that is, to minimize $\sum^n_{i=1}\limits c_i$. Give an algorithm that schedules the tasks so as to
minimize the average completion time. Each task must run non-preemptively, that is, once task ai starts, it must run continuously for $p_i$ units of time. **Prove** that your algorithm minimizes the average completion time, and state the running time of your algorithm.


題目在講說現在有$a_i$到$a_n$個工作，每個工作需要$p_i$的時間來完成且完成時間為$c_i$，此題只有一個機器可以執行工作且一次執行一個，每個工作一但執行就不能終止。求最小的平均完成時間

Proof Greedy idea, minimum $p_i$ first.
- Give task $a$ and $b$ , and $p_a < p_b$
- Let $O$ be the task sequence of optimal solution.
- $a$ is the smallest processing time task.
-  If $b$ is the first task and $a$ is the second task of $O$
- Let $G$ is a task sequence switch the order $a$ and $b$ in $O$ 
- Completion time of $G$ is less than or equal completion time of $O$. proving minimum $p_i$ do first.

Time complexity $O(nlgn)$
#### pseodo code
```
minimum_time_Scheduling(a[],p[])
    sort task by processing time from smallest ro largest
    new p[1] <= p[2] ... <= p[n]
    temp <- 0
    sum <- 0
    for i=1 to n
       temp = temp + p[i]
       sum = sum + temp
    return sum/n
```


### Problem 3

Suppose you have one machine and a set of n jobs $a_1, a_2, ...$, to process on that machine. Each job $a_j$ has a processing time $t_j$, the same profit 1, and a deadline $d_j$. The machine can process only one job at a time, and job $a_j$ must run uninterruptedly for $t_j$ consecutive time units. If job $a_j$ is completed by its deadline $d_j$, you receive a unit profit, but if it is completed after its deadline, you receive a profit of 0. Give an algorithm to find the schedule that obtains the maximum amount of profit.


- idea
    - Every task has the same profit. $\to$ The more task we finish, the more profit we get.
    - According to Lemma 16.12，we know that the sum of all the execution time will less than the deadline of the latest task.


- pseudo code
    - sum = 0：the sum of all execution time
```
task_scheduling:
    tasks[] <- sorted by min deadline
    S <- priority queue, sorted by max t[i]
    for i in |tasks|
        S.push(t[i])
        sum+=t[i]
        if(sum > d[i])
            sum-=t[S.top]
            S.pop()
    sol <- sort S by min deadline
return sol 
```
- time complexity: $O(n)$
- proof：
    Set $S=\{x_1, x_2, ... x_n\}$ is one of the optimal solution, and $S$ is sorted by deadline in ascending order.
    If there is a task $k \notin S$ whose execution time is less than $x_i$ which has the longest exection time, and its deadline is before $x_n$, we can replace $x_i$ with $k$, and still get a optimal solution.
    
    <!--嚇鼠你-->