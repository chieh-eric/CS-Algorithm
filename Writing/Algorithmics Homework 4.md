# Algorithmics Homework 4
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

Show, by means of a counterexample, that the following “greedy” strategy does not always determine an optimal way to cut rods. Define the density of a rod of length $i$ to be $\dfrac{p_i} {i}$, that is, its value per inch. The greedy strategy for a rod of length n cuts off a first piece of length $i$, where $1 \le i \le n$, having maximum density. It then continues by applying the greedy strategy to the remaining piece of length $n-i

assume $n = 4$

| length $i$ | 1 | 2 | 3 | 4 |
| -------- | -------- | -------- | -------- | -------- |
| **price $p_i$** | 1 | 12 | 21 | 16 |
| **density $p_i/i$** | 1 | 6 | 7 | 4 |
- by "greedy" strategy
  STEP 1: cutting off a first piece of length 3
  STEP 2: remaining piece of length 1
  $\Rightarrow$ total price is 1 + 21 = 22
- However, the optimal way is cutting into two piece of length 2
    $\Rightarrow$ total price is 12 + 12 = 24

### Problem 2

Consider a modification of the rod-cutting problem in which, in addition to a price pi for each rod, each cut incurs a fixed cost of c. The revenue associated with a solution is now the sum of the prices of the pieces minus the costs of making the cuts. Give a dynamic-programming algorithm to solve this modified problem.


```
MODIFY_Cut-Rod(p,n,c)
    let r[0...n] a new array
    r[0] = 0
    for j = 1 to n
        q = p[j]
        for i = 1 to j - 1
            q = max(q,p[i]+r[j-i]-c)
        r[j] = q
    return r[n]
```


Initial value $r[0]=0$
Recursive function $r_j=max_{1\leq i\leq j-1}\{p_i+r_{j-i}\}$
This pseudocode is refer to Buttom-Up Method.
The major modification is inside the inner for-loop,$q = max(q,p[i]+r[j-i]-c)$, we add $c$ which means the fixed cost in this function.However we should also consider the 0 cut problem(while i equal j), we assign $q=p[j]$ ,then can simply give the no cut rod a value, moreover we also run the inner for-loop from $j-1$ instead of $j$ . If we dont't handle this modification , we may deduct too much $"c"$ .
<!-- 
Kenny 為什麼你這次這麼早寫QQ
-->
### Problem 3 

Modify MEMORIZED-CUT-ROD to return not only the value but the actual solution, too.

- Idea
    - Initial value $r_0 = 0$
    - Recursive function $r_n = max_{1\le i\le n}\{p_i+r_{n-i}\}$
    - Use an array to memorize the cut point
    - Use other function to show solution
- Pseudo Code
~~~
func Memorized_Cut_Rod(n)
    if r[n]>=0  return r[n]
    q = -infinity
    for i=1 to n 
        if q < p[i]+Memorized_Cut_Rod(n-i)
            q = p[i] + Memorized_Cut_Rod(n-i)
            s[n] = i
    r[n] = q
    return q
end func

func printSolution(n)
    print "the optimal value is" Memorized_Cut_Rod(n)
    print "the cut are at"
    i = n
    j = 0
    while j<n
        print j+s[i]
        i = n-j-s[i]
        j = j+s[i]
end func
~~~

### Problem 4

Find an optimal parenthesization of a matrix-chain product whose sequence of dimensions is《5, 10, 3, 12, 5, 50, 6》.


$<a_n>=<5, 10, 3, 12, 5, 50, 6>$
| matrix | $M_1$ | $M_2$ | $M_3$ | $M_4$ | $M_5$ | $M_6$ |
|:------:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|
|  size  | 5x10  | 10x3  | 3X12  | 12x5  | 5x50  | 50x6  |

* compute $M_1M_2M_3M_4M_5M_6$ optimization
* $DP[start, end]=(cutpoint, time)$ denote optimized manipulation for $M_{start}M_{start+1}...M_{cutpoint}...M_{end}$
*  and the optimized manipulation happen when $(M_{start}M_{start+1}...M_{cutpoint})(M_{cutpoint+1}...M_{end})$
* $\text{initial case}:\forall_{i}DP[i, i]=(i, 0)$
* $DP[start, end]=(\text{i that gives the minimal}, \min(\forall_{start\le i< end}DP[start, i]+DP[i+1, end]+a_{start-1}*a_{i}*a_{end}))$

|  DP   |  start=1  |  start=2  |  start=3  |  start=4  |  start=5  | start=6 |
|:-----:|:---------:|:---------:|:---------:|:---------:|:---------:|:-------:|
| end=1 |  (1, 0)   |     X     |     X     |     X     |     X     |    X    |
| end=2 | (1, 150)  |  (2, 0)   |     X     |     X     |     X     |    X    |
| end=3 | (2, 330)  | (2, 360)  |  (3, 0)   |     X     |     X     |    X    |
| end=4 | (2, 405)  | (2, 330)  | (3, 180)  |  (4, 0)   |     X     |    X    |
| end=5 | (4, 1655) | (2, 2430) | (4, 930)  | (4, 3000) |  (5, 0)   |    X    |
| end=6 | (2, 2010) | (2, 1950) | (4, 1770) | (4, 1860) | (5, 1500) | (6, 0)  |

$\text{answer for question: }(M_1M_2)((M_3M_4)(M_5M_6)), \text{minimal: }2010$

pseudo code (index start from 1, number of matrix=n, a is matrix chain array)
```
process findOptimalMatrixChainProduct(a, n)
    for i = 1 to n
        dp[i][i]=(i, 0)
    for gap = 1 to n-1
        for start = 1 to n
            end = start + gap
            break if end > n
            minimal = (cutpoint=0, time=inf)
            for cutpoint = start to end-1
                time = dp[start][cutpoint] + dp[cutpoint+1][end] 
                        + a[start-1]*a[cutpoint]*a[end]
                minimal = (cutpoint, time) if time < minimal.time 
            dp[start][end]=minimal
    return dp[1][n]
    
process printProductChain(start, end)
    if start==end
        print('M'+start)
    else 
        print('(')
        printProductChain(start, dp[start][end].cutpoint)
        printProductChain(dp[start][end].cutpoint+1, end)
        print(')')
```
<!--[C++ code](https://hackmd.io/uS0NB2aPQiKHEHTmyI9YqQ)-->


<!--安安
那個
你知道 好像是第4提要報告ㄇ
我好像有聽說哈哈

你很從容噢 看   wooooohoooooooooo 反正 禮拜天可以再決定
也是哈哈
我不太介意再報告一次啦
但這樣下次是不是還是會輪到我啊
提議：猜拳決定
提議：等到下次再說
提議：讓羊報告
羊呢 看到請回復
??為啥是羊 領頭羊
好ㄟ贊同
ok看來我們很有默契-->

### Problem 5 
:::info
A mathematical expression is given without parentheses. Design an algorithm to parenthesize the expression such that the value of the expression is maximized. For example, consider the expression: 2+7⋅5. There are two ways to
parenthesize the expression 2+(7⋅5) = 37 and (2+7)⋅5 = 45, so in this case, your algorithm should output the second expression. Here, you may assume the given expressions contain only 3 kinds of binary operators ‘+’, ‘−’, and ‘⋅’.
:::
Idea
- 類似於matrix-chain product，只是運算子多了+\-。
- 題目要算出最大值，因為運算子有-+*所以需紀錄最小值和最大值。
- mincut[]紀錄最小值的cutpoint,maxcut[]紀錄最大值的cutpoint,minval[]紀錄最小值初始值皆為$\infty$，maxval[]紀錄最大值初始值皆為$-\infty$。
- 數學式先sort成number[]和operater[]
- 遞迴關係式
$minval[i][j] =min_{i\le k\lt j}\left\{ 
  \begin{array}{c}
    maxval[i][k]\ operater[k]\ maxval[k+1][j] \\ 
    maxval[i][k]\ operater[k]\ minval[k+1][j] \\ 
    minval[i][k]\ operater[k]\ maxval[k+1][j] \\
    minval[i][k]\ operater[k]\ minval[k+1][j]
  \end{array}
\right.$
\
$maxval[i][j] =max_{i\le k\lt j}\left\{ 
  \begin{array}{c}
    maxval[i][k]\ operater[k]\ maxval[k+1][j] \\ 
    maxval[i][k]\ operater[k]\ minval[k+1][j] \\ 
    minval[i][k]\ operater[k]\ maxval[k+1][j] \\
    minval[i][k]\ operater[k]\ minval[k+1][j]
  \end{array}
\right.$
```
process findMaxOutput(operater,number, n) //n= len(operater)
    for i = 0 to n-1
        maxval[i][0]&minval[i][0] = number[i]
        mincut[i][0]&maxcut[i][0] = i
    for gap = 1 to n-1
        for start = 0 to n-1
            end = start + gap
            if (end >= n)break
            for cutpoint = start to end-1
                result = val[start][cutpoint] operater[cutpoint] val[cutpoint+1][end]
                //上面這句省略了minmax的四種可能,val含minval和maxval
                //下面的cutpoint會記錄是從minval還是maxval得到result
                if (result < minval[start][end])
                    minval[start][end] = result
                    mincut[start][end] = cutpoint
                if(result > maxval[start][end]) 
                    maxval[start][end]= result
                    maxcut[start][end] = cutpoint
            
process printMaxOutput(start, end)//operater的start end
    if start==end
        print(number[start])
    else 
        print('(')
        //以下省略了cutpoint是從哪裡得到的,cut可能為maxcut或mincut 
        printMaxOutput(start, cut[start][end])
        print(op[cutpoint])
        printMaxOutput(cut[start][end]+1, end)
        print(')')
```
> 齁齁抓 有大！！！蟲蟲嘔 求助教不要看到5555[time=Tue, Apr 5, 2022 9:43 PM]
> 4/8  改完ㄌ

### Problem 6
Which is a more efficient way to determine the optimal number of multiplications in a matrix-chain multiplication problem: enumerating all the ways of parenthesizing the product and computing the number of multiplications for each, or running RECURSIVE-MATRIX-CHAIN? Justify your answer.
```
RECURSIVE-MATRIX-CHAIN(p, i, j)
	return 0 if i == j
	m[i][j] = ∞
	for k in i...j
		q = RECURSIVE-MATRIX-CHAIN(p, i, k) +
			RECURSIVE-MATRIX-CHAIN(p, k + 1, j) +
			p[i - 1] * p[k] * p[j]
		m[i][j] = q if q < m[i][j]
	return m[i][j]
```
:::
<!-- 
resources:
- https://walkccc.me/CLRS/Chap15/15.3/
 -->
- Enumeration
	1. 	The number of all possible answers satisfied the sequence of Catalan Number.
	2. 	$n^{th}$ Catalan Number = $\dfrac{C_n^{2n}}{n+1} \sim \dfrac{4^n}{n^{3/2}\sqrt\pi} \in \Omega(\dfrac{4^n}{n^{3/2}})$ (By Stirling's formula)

- RECURSIVE-MATRIX-CHAIN (without DP)
	$\begin{split}
	T(n)&\le\left\{\begin{matrix}
		c &, n = 1\\
		c +\sum_{k=1}^{n-1}\limits(c+T(k)+T(n-k)) &,n\ge 2
	\end{matrix}\right.\\
	&\le2\sum_{i=1}^{n-1} T(i) + cn\\
	&(\text{Assume that } T(n)\le c\cdot n3^{n-1}, \text{using substitution method})\\
	&\le 2\sum_{i=1}^{n-1} c\cdot i\cdot 3^{i-1} + cn\\
	&\le c\cdot\left(2\sum_{i=1}^{n-1} i\cdot 3^{i-1} + n\right)\\
	&= c\cdot\left(2 \left( \dfrac{n\cdot3^{n-1}}{3-1} + \dfrac{1-3^n}{(3-1)^2} \right) + n\right)\\
	&= c{n\cdot3^{n-1}} + c\cdot\left(\dfrac{1-3^n}{2} + n\right)\\
	&= c{n\cdot3^{n-1}} + \dfrac c2\cdot\left(1-3^n + 2n\right)\\
	&\le c{n\cdot3^{n-1}}\ \ \forall c>0, n\ge1
	\end{split}$
	- Time Complexity : $O(n\cdot 3^{n-1})$
- Result
	- running RECURSIVE-MATRIX-CHAIN is more efficient than enumerating all the ways.
	- Using dynamic programming will perform better than both above.

### Problem 7

As stated, in dynamic programming we first solve the sub-problems and then choose which of them to use in an optimal solution to the problem. 
Professor Capulet claims that it is not always necessary to solve all the sub-problems in order to find an optimal solution. 
She suggests that an optimal solution to the matrix-chain multiplication problem can be found by always choosing the matrix $A_k$ at which to split the sub-product $A_iA_{i+1}...A_j$(by selecting $k$ to minimize the quantity $p_{i-1}p_kp_j$) before solving the sub-problems. 
Find an instance of the matrix-chain multiplication problem for which this greedy approach yields a sub-optimal solution.

<!-- 
可惡我也想要粉紅色RRRRR
 -->

Hint: Compare the two method: 
1. DP
2. choosing the matrix $A_k$ at which to split the sub-product $A_iA_{i+1}...A_j$(by selecting $k$ to minimize the quantity $p_{i-1}p_kp_j$)

Give an counter example 
$<a_n>=<5, 6, 3, 2>$

| matrix | $M_1$ | $M_2$ | $M_3$ |
|:------:|:-----:|:-----:|:-----:|
|  size  |  5x6  |  6x3  |  3X2  |


- DP: 
$\begin{split}\\(M_1(M_2M_3))&=6\cdot3\cdot2+5\cdot6\cdot2\\
&=36+60\\
&=96\end{split}$

- The method from the problem: 
split: 
$\begin{split}\\((M_1M_2)M_3)&=5\cdot6\cdot3+5\cdot3\cdot2\\
&=90+30\\
&=120\end{split}$

- $\Rightarrow 120>96 \Rightarrow$ the method from the problem is sub-optimal solution