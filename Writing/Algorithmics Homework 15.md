# Algorithmics Homework 15
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

Exercises 34.4-7
Let 2-CNF-SAT be the set of satisfiable Boolean formula in CNF with exactly 2 literals per clause. Show that 2-CNF-SAT ∈ P. Make your algorithm as efficient as possible.
(Hint: Observe that x ∨ y is equivalent to ¬x → y. Reduce 2-CNF-SAT to an efficiently solvable problem on a directed graph.)

2-CNF-SAT formula: $\land_i(X_i \lor Y_i)$
- Consider a directed graph G
    - $X \lor Y$ is equivalent to$\lnot X \to  Y$
    - for each variable $x_i$, add two vertices $x_i,\ \overline{x_i}$ to G
     <!--![](https://i.imgur.com/JkL5t7u.png =150x)-->
    - for each clauses, add two edge $\overline{X}Y$  and $\overline{Y}X$ to G
    - if there is n clauses, the number of vertices in G less than 2n, the number of edge in G equals to 2n.
    <!-- // So an edge on the graph means: if it comes from true, it will go to true.-->
    - Then, in order to say that the formula is satisfiable, what we would need to see is a path from a vertex to the negation of that vertex
    <!-- //The naive way of doing this would be to run all pairs shortest path, and see if there is a path from a vertex to its negation. And it takes $O(n^2\lg n)$-->
    - The efficient way is to find Strong Connected Components. Which takes linear time: $O(V+E)=O(V)$

    - For every pair of variable and negation, **make sure that they are not in the same strongly connected component.**
    - if $X$and $\overline X$ are in the same strongly component, then $\land_i(X_i \lor Y_i)$ is not satisafiable.
- Assignment
    - Such an assignment corresponds to a set of truth values for the variables which makes $\land_i(X_i \lor Y_i)$ true if and only if: 
        - **i.** For all i, vertices $x_i$ and $\overline{x_i}$ receive complementary truth values. 
        - **ii.** There must be even number of strongly connected components.Topsort the SCC. Suppose there is 2n components, then components $[a_1,a_2,a_3...,a_n,...,a_{2n}]$ is topological. 
            Set $a_{n+1}$ to $a_{2n}$ true (it is to set sink true, since there are n sink at most)，then since the graph is symmetirc, $a_1$ to $a_n$ will be false.
- Example
    ![](https://i.imgur.com/ssKrFHi.png)
    - there are 6 components in this graph
    - there are two sink : $\overline{c}$ and $a$ 
    - then we assign $\overline{c}$ and $a$ are true.
    - the components $\overline bd,\overline db$ ,choose one component set true,then b:true,d:false  
    - the final assginment would be: $a:true,b:true,c:false,d:true$,which is satisfy the formula.

    <!--  Since our construction was symmetric with respect to taking negations, if there were a path from a variable to its negation, there would be a path going from its negation to itself as well.
    - This means that we would detect any path from a variable to its negation, just by checking to see if they are contained in the same connected component or not.-->

<!--[參考](https://sites.math.rutgers.edu/~ajl213/CLRS/Ch34.pdf)
https://mathweb.ucsd.edu/~sbuss/CourseWeb/Math268_2007WS/2SAT.pdf
-->
### Problem 2 

Exercises 34.5-1
The subgraph-isomorphism problem takes two undirected graphs G1 and G2, and it asks whether G1 is isomorphic to a subgraph of G2. Show that the subgraph - isomorphism problem is NP-complete.

To prove $\text{subgraph-isomorphism problem}\in NP-complete$, 
we want to prove $\text{subgraph-isomorphism problem}\in NP$ and $\text{clique problem} \leq\text{subgraph-isomorphism problem}$ in which we use $\text{clique problem}$ as already known $NP-complete$ problem.

Prove $\text{subgraph-isomorphism problem}\in NP:$
x(input):G1, G2 check whether there is sub-graph in G1 that is isomorphc with G2
y(certificate): f(x) which is vertex injection function from G2 to G1
A(x, y):Check whether G2 is image of G1's sub-graph denoted by f

Prove $\text{clique problem} \leq\text{subgraph-isomorphism problem}$:
For a $\text{clique problem}$ we translate it into a $\text{subgraph-isomorphism}$ problem by setting $G1$ as clique problem's input, $G2$ as a complete graph with vertix size k. Solve $\text{subgraph-isomorphism problem}$ with input $<G1, G2>$, so $\text{clique problem} \leq\text{subgraph-isomorphism problem}$

### Problem 3 

Exercises 34.5-2
Given an integer $m \times n$ matrix $A$, and an integer m-vector b, the 0-1 integer-programming problem asks whether there exists an integer n-vector x with elements in the set {0, 1} such that Ax ≤ b. Prove that 0-1 integer programming problem is NPcomplete. (Hint: Reduce from 3-CNF-SAT.)

- Step 1: Prove the problem is in NP
    - $Ax$ can be computed in $O(nm)$
    - comparison $Ax$ and $b$ can be performed in $O(m)$
    - $\Rightarrow$ the problem can be verified in polynomial time $\Rightarrow$ the problem is in NP 
- Step 2: Prove 3-CNF-SAT $\le_P$ 0-1 Integer-Programming
    - A:
        - $a_{i,j}=\left\{ 
          \begin{array}{l}
            -1\ \ \ \ \text{  if variable j occurs only without negation in clause i} \\ 
            1\ \ \ \ \ \text{  if variable j occurs only with negation in clause i} \\ 
            0\ \ \ \ \ \text{  otherwise}
          \end{array}
            \right.$
    - n-vector x
        - $x_{i}=\left\{ 
          \begin{array}{l}
            1\ \ \ \ \ \text{  if variable i is assigned True} \\ 
            0\ \ \ \ \ \text{  if variable i is assigned False}
          \end{array}
            \right.$
    - m-vector b
        - If $\Phi=(x_1\vee x_2\vee x_3)\Rightarrow (x_1+ x_2+ x_3)\ge1\Rightarrow(-x_1-x_2-x_3)\le-1$
        - If $\Phi=(x_1\vee x_2\vee -x_3)\Rightarrow (x_1+ x_2+1- x_3)\ge1\Rightarrow(-x_1-x_2+x_3)\le0$
        - $\Rightarrow b_i=-1+\text{the number of negated literals in clause i}$
    - Therefore, $y=Ax\le b\Leftrightarrow x \text{ is an assignment satisfying }\Phi$
        $\because$ 3-CNF-SAT is in NP-complete 
        $\therefore$ 0-1 integer programminig is also in NP-complete
- [有參考但看不懂嗚嗚](https://gnarlyware.com/blog/proving-0-1-integer-programming-is-np-complete-using-reduction-from-3-cnf-sat/)
- [參考2](https://math.stackexchange.com/questions/1247005/need-help-to-understand-the-solution-for-np-completness-proof-3cnf-0-1-integ)

### Problem 4 (金魚)

Exercises 34.5-7
Based on hw14-7,we know that longest-simple-cycle problem is an NP-problem. Prove that the problem is NP-complete.

To prove longest-simple-cycle $\in$ NP-complete problem:
- Step 1: Prove that the $\text{longest-simple-cycle problem} \in NP$ 
    - Decision problem: give a graph $G$, if there is a simple-cycle that contains at least $k$ vertice, the the answer is 1, otherwise, the answer is 0.
    - Certificate: give a vertices set $y=\{v_1, v_2, ..., v_n\}, n \ge k$, walk through the set, if it is a simple cycle, then cirtificate that this is a NP problem.
- Step 2: Reduce the $\text{hamiltonian cycle}$ problem to the $\text{longest-simple-cycle}$ problem
    - Input $<G, k>$: the input graph $G$ has a simple cycle with at least $k$ vertices
    - Decision problem: 
        - if $<G, k>$ = 1 ( there is a simple cycle in G ), then we can say that there is a Hamiltonian cycle in G.
        - if $<G, k>$ = 0 ( there is no simple cycle in G ), then we can say that there is no Hamiltonian cycle in G.
    - ∵ Hamiltonian Cycle is in NP-complete
        ∴ Longest Simple Cycle is also in NP-complete


