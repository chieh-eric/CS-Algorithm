# Algorithmics Homework 3
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

在課本 4.1 節中(p.68)作者將 stock buying problem 轉成 maximum-subarray problem 再用 Divide-and-conquer 的概念來解此問題，請給一個 $O(n)$執行時間的Pseudo code algorithm 直接解 stock buying problem，毋需再做任何transformation。

```
func stock(arr): int
    sell <- 0
    buy <- maximun_int
    profit <- 0
    for(int i = 0; i < arr.size() ; i++)
        if(arr[i] < buy)
            buy = arr[i]    #find smaller buying value
        sell = arr[i] - buy
        if (profit < sell)
            profit = sell
    return profit
```
<!-- > 不建議用min跟max當變數名，因為在有些語言裡可以當函數用 [name=大俠] -->

### Problem 2
Let $A[1..n]$ be an array of n distinct numbers. If $i<j$ and $A[i] > A[j]$, then the pair $(i, j)$ is called an *inversion* of $A$.
a. List the five inversions of the array 〈2, 3, 8, 6, 1〉.
b. What array with elements from the set {1, 2,..., n} has the most inversions? How many does it have?
c. What is the relationship between the running time of the insertion sort and the number of inversions in the input array? Justify your answer.
d. Give an algorithm that determines the number of inversions in any permutation on n elements in $\Theta(n\lg n)$ worst-case time. (Hint: Modify merge sort.)


a. 
- (1, 5), (2, 5), (3, 5), (3, 4), (4, 5)


b. 
- array:〈n, n-1, ...., 2, 1〉
- number of pairs: n(n-1)/2 ,since any pair in the array is inversion

c.
- sort the array using insertion sort by the value of element, then once the element is swap the number of inversion pair+=1
- since if there is no swap when doing insertion sort, the for loop beak. The relationship between running time of insertion sort and the number of inversions is $T(n)=\Theta (g(n)+n)$, which $g(n)$ denote the number of inversions, and the n in theta notation comes from the comparism after each last swap.
<!-- 
程式作業那個交了的484你
y XD
 可惡RRRRRRRR
哈哈哈
所以剩下那個AC是你喔
沒我還沒寫
我只寫完n^2的

哦哦
n^2得也會用到
小於threshold的時候
我有查到現成的code
因為我想說順便學一下 pair就慢慢查
哦哦
我用class
因為有些比較函式用class寫比較嚴謹一點點
我比較不習慣寫class
直接用iter也太硬
我都用index
想說這樣比較漂亮(?
我沒有認真看過iter
那個時候還笨笨的
但我不知道有沒有比較快就是ㄌ
不知哈哈
搞不好他轉完根本長一樣
笑死XDD

我記得我之前有一次心血來潮想要拚ds第一個AC，洗個澡回來你就過ㄌ
哈哈哪一個啊
我禮拜四晚上練球如果六點不寫完就得等十一點以後了哈哈
忘了欸好像是dfs那題

https://dsoj.ncu.edu.tw/acm-rank
ㄟ等一下所以3個AC有一個是助教的意思嗎
有2個
我送了兩次
因為第一次得好像有bug
不過還是AC了
顯然大家還不夠瘋狂
哈哈我其實下午就寫完了晚上才看到OJ
哀輸了
我還在想說他還沒公告pdf
我下午在寫我的MIPS
哦哦我昨天寫得
好麻煩而且昨天還沒教div要自己查
組語-2.0
我覺得全部都是指令感覺比較好
上學期組與學一學又多了一堆奇怪的東東頭好痛
我是覺得組語看起來整齊多了
都沒啥興趣奇奇怪怪的指令好難記
你專題做啥啊
量子機器學習
wow 之前聽說明會就覺得好硬腦袋在星爆
之前說明會是江振瑞但其實他根本沒在做只是隨便講講 xd
結果還是抱戴維大腿找孫敏德
哈別擔心我自己也不知道她在幹嘛
所以你是跟peter?對
雞翅才是跟江振瑞
然後雞翅其實現在試辦放養狀態哈哈
我想說你的專題怎麼也這麼硬現在就有meeting
其實應該是有些專案負責的學長姊要畢業了
所以有些需要交接然後大家就一起開始了 噢嗚

可以直接按ctrl+/
哦哦
打完一學期演算法大家都會變hackmd大師ㄉ
我覺得不會我打了一學期離散
結果連table都還要查怎麼打
table我都按上面快捷鍵
我都快忘記上面還有那一排了
先下 困了 明天早9
掰掰 我也收工了灑花
下一團 應該明天早上在上課睡覺
OS超好睡
沒錯
我打算明天OS來幹我的演算法
掰餔
掰
-->
<!-- XD hackmd大師-->

d.
- input: array
     output: an integer $i$ as the number of inversion pair
     1. initialize $i=0$
     2. sort the array list using merge sort
        when merging the list, if any element in the right   half array is merged
        add $i$ with the number of element left in the left half array
- time complexity:
    we can use integer to store the number of element left in the list so that any add operation take $\Theta(1)$ time, so the time complexity is identical with merge sort which is $\Theta(n\lg n)$

<!--  至少寫得出來哈哈 我又遇到水題了好開心
沒有啦大家應該都想得出來只是題目看起來比較長
晚安:)
哈哈早死早超生等等還要做別的是先來寫個作業放鬆一下XD
不要數學都好
哈哈這次都沒有數學
吧?
吧 
-->
### Problem 3
Professor Howard have proposed the following “elegant sorting” algorithm:
~~~
STOOGE SORT(A, i, j) 
{ 
	if A[ i ] > A[ j ] 
		then exchange A[ i ] <-> A[ j ]
	if i + 1 >= j
		then return 
	k <- ⌊ (j – i + 1) / 3⌋ 
	STOOGE SORT(A, i, j - k) 
	STOOGE SORT(A, i + k, j) 
	STOOGE SORT(A, i, j - k)
}
~~~


<!--
鐵蛋の註解我不知道怎麼註解就拉出來ㄌ
STOOGE SORT(A, i, j) 

鐵蛋加油 我們要去補影片ㄌㄎㄎ
嘔屋 你不該跟我講可惡 這樣就不會想看ㄌXDDD
哈哈好雖然好像沒有這題
好酷的題目
有點像(321)->(231)->(213)->(123)?
-->
#### a. Determine whether the sorting algorithm is in place and whether it is stable.
Ans. in place，因為是透過呼叫函式來交換前後，用到的除了stack就是交換時用的O(1)。
unstable，反例：$3_1,2,3_2,1$
sort(1,4) $3_1,1交換 \rightarrow 1,2,3_2,3_1$
sort(1,3) $\rightarrow \{1,2,3_2\},3_1$
sort(2,4) $\rightarrow 1,\{2,3_2,3_1\}$
sort(1,3) $\rightarrow \{1,2,3_2\},3_1$
從以上步驟可以發現$3_1$不會再被挪動，所以只要在陣列的第一個數字被交換到最後面，就會unstable。


#### b. Argue that, if ```n = length[A]```, then ```STOOGE SORT(A, 1, length[A])``` correctly sort the input array ```A[1 ... n]```
<!--1.STOOGE SORT(A, 1, length[A])，會先排序好前三分之二的陣列再排序後三分之二，再排序前三分之二，所以會全部排過就排好了。
2.
```
STOOGE SORT(A, i, j) 
{ //假如大小為n
	if A[ i ] > A[ j ] 
		then exchange A[ i ] <-> A[ j ]
	if i + 1 >= j
		then return //n<=2時會排好
	k <- ⌊ (j – i + 1) / 3⌋ //k=⌊n/3⌋
	STOOGE SORT(A, i, j - k) 
	STOOGE SORT(A, i + k, j) 
	STOOGE SORT(A, i, j - k)
    /*這三行跑完因為n<=2會排好所以n<=3時會排好
    這三行跑完因為n<=3會排好所以n<=4時會排好(⌊n/2⌋*3+1)
    這三行跑完因為n<=m會排好所以n<=⌊m/2⌋*3+1時會排好(數學歸納法得證)  
    (因為要重複1/3所以會是m/2*3+1)
    */
}
```
所以只要stooge sort(A,i,j)i放起始，j放陣列長度，就會把陣列排好。
3.-->
j-i=1時，會在line 6 時return，完成一次排序。
n=2時，會在line 6 排好。
n=3的時候，會切成長度為2的數列進行sort，因為n=2會排好，所以n=3會排好。
n=4，可切成長度為3的數列進行sort，因為n=3會排好，所以n=4會排好。
當n=m時，會分成長度$\dfrac {2m}{3}$的數列進行sort，因為可以一直分下去sort，所以可以推出數列長度為m會排好。



#### c. Give a recurrence for the worst-case running time of *STOOGE SORT* and a tight asymptotic ($\Theta$-notation) bound on the worst-case running time.
$T(n)=3T(\dfrac{2n}3)+O(1)$
by master theorem,$a=3,b=\frac{3}{2},k=0$
$0<log_\frac323$
$T(n)=\Theta(n^{log_\frac323})$


#### d. Compare the worst-case running time of *STOOGE SORT* with insertion sort, merge sort, heapsort, and quicksort. Do the professor deserve tenure?
$log_\frac323=2.7095112914$
merge sort:$O(n\lg n)$
insertion sort:$O(n^2)$
heapsort:$O(n\lg n)$
quicksort:$O(n\lg n)$
$O(n^{2.7095112914})>O(n^2)$
$O(n^2)$已經是傳統的排序中最爛的了，這個演算法不值得被放進sort教學。

<!--https://www.ic.unicamp.br/en/~meidanis/courses/mo417/2003s1/exercicios/2003-03-19.html 參考參考借鑑借鑑-->

### Problem 4

How would you modify Strassen’s algorithm to multiply n×n matrices in which $n$ is not an exact power of 2? Show that the resulting algorithm runs in time $\Theta(n^{\lg 7})$.

We can pad zero from origin $n \times n$ matrix to $m \times m$ matrix.
Define $2^k<n<2^{k+1}=m < 2^{k+2}$ and $m<2n$, so it won't affect the asymptotic complexity.
Through Strassen's algotithm,we can know $T(n)=\Theta(m^{\lg 7})$
beacuse $m$ must smaller than $2n$
$\rightarrow T(n)=\Theta((2n)^{\lg7})=\Theta(n^{\lg 7})$

### Problem 5
Pan has discovered a way of multiplying $68×68$ matrices using $132,464$ multiplications, a way of multiplying $70×70$ matrices using $143,640$ multiplications, and a way of multiplying $72×72$ matrices using $155,424$ multiplications. Which method yields the best asymptotic running time when used in a divide-and-conquer matrix-multiplication algorithm? How does it compare to *Strassen’s algorithm*?

<!-- http://hscc.cs.nthu.edu.tw/~sheujp/lecture_note/14algorithm/Chap4_HW-1.pdf
-->
- Strassen's algorithm ( $2×2$ matrices using $7$ multiplications )
    - $T_0(n) = 7 \cdot T_0(\frac n2) + \Theta(n^2) = \Theta(n^{\lg7}) = O(n^{2.807355})$
- $68×68$ matrices using $132,464$ multiplications
    - $T_1(n) = 132464\cdot T_1(\frac n{68}) + \Theta(n^2) = \Theta(n^{\lg_{68}^{132464}}) = O(n^{2.795128})$
- $70×70$ matrices using $143,640$ multiplications
    - $T_2(n) = 143640\cdot T_2(\frac n{70}) + \Theta(n^2) = \Theta(n^{\lg_{70}^{143640}}) = O(n^{2.795123})$
- $72×72$ matrices using $155,424$ multiplications
    - $T_3(n) = 155424\cdot T_3(\frac n{72}) + \Theta(n^2) = \Theta(n^{\lg_{72}^{155424}}) = O(n^{2.795147})$

$\Rightarrow T_2(n) < T_1(n) < T_0(n) < T_3(n)$
$\Rightarrow$ thus we obtain that $70 \times 70$ with $143640$ multiplications yields the best asymptotic running time.

### Problem 6 

How quickly can you multiply a $kn\times n$ matrix by an $n\times kn$ matrix, using Strassen’s algorithm as a subroutine? Answer the same question with the order of the input matrices reversed.

<!-- 把n*n看成一個元素kn*n的矩陣*n*kn的矩陣只需要k*T(n*n)=O(kn^2.8...) 
感謝鐵蛋 無敵大感謝
-->
設 $A$ 為 $kn \times n$ matrix，$B$ 為 $n \times kn$ matrix.
$A=\begin{bmatrix}A_1 \\ \vdots \\ A_k\end{bmatrix}$, $B=\begin{bmatrix} B_1 \cdots B_k \end{bmatrix}$，$A_i$、$B_i$ 為 $n \times n$ matrix.
$A \times B$ 為 $kn \times kn$ matrix，又每個 $A_i \times B_i$ 為 $n \times n$ matrix.

$\Rightarrow$$\begin{bmatrix}
  A_{1}B_1 & \cdots & A_{1}B_k\\
  \vdots & \ddots & \vdots\\
  A_{k}B_1 & \cdots & A_{k}B_k
\end{bmatrix}$

根據 Strassen's algorithm，計算 $A_i \times B_i$ 的時間複雜度為 $\Theta(n^{\lg 7})$
一共有 $k \times k$ 個 $A_i \times B_i$，則 $A \times B$ 的時間複雜度為 $\Theta(k^2n^{\lg 7})$

**Reversed Order**
若計算 $B \times A$
$\Rightarrow B \times A = \begin{bmatrix} B_1 \cdots B_k \end{bmatrix}\begin{bmatrix}A_1 \\ \vdots \\ A_k\end{bmatrix}= \sum\limits^k_{i=1}B_iA_i$
$\Rightarrow$ 計算每個 $B_iAi$ 需要 $n^2$ 的乘法，總和則需要 k-1 次加法
$\Rightarrow B \times A$ 的時間複雜度為 $\Theta(kn^{\lg 7})$

### Problem 7
**Young tableaus**
An $m \times n$ **Young tableau** is an $m \times n$ matrix such that the entries of each row are in sorted order from left to right and the entries of each column are in sorted order from top to bottom. Some of the entries of a Young tableau may be $\infty$ , which we treat as nonexistent elements. Thus, a Young tableau can be used to hold $r\le mn$ finite numbers.

<!-- 好像有點類似heap tree只是父節點改成上面或左邊? --
感謝鐵蛋 From 小林
感謝鐵蛋嗚嗚嗚嗚嗚嗚
哈哈去感謝歐宸宸-->
#### a. Draw a 4 $\times$ 4 Young tableau containing the elements {9, 16, 3, 2, 4, 8, 5, 14, 12}.
- $\begin{bmatrix}2 & 3 & 9 & 12 \\4 & 8 & 14 & \infty \\5 & 16 &\infty &\infty \\ \infty &\infty &\infty &\infty \end{bmatrix}$


#### b. Argue that an $m \times n$ Young tableau $Y$ is empty if $Y[1, 1] = \infty$. Argue that $Y$ is full(contains $mn$ elements) if $Y[m, n] \lt\infty$.
<!-- 左邊跟上面都要比那個元素小所以如果右下不是無限救全部都滿了 -->
- $\because$ All of element in first row need to be larger than $Y[1, 1]$
    $Y[1, 1] = \infty \Rightarrow$  all elements in first row need to be $\infty$. 
    All other elements need to be larger than the first element in their column.
    $\therefore$ all elements are $\infty\Rightarrow Y$ is empty 
    
- $\because$ All of element in last row need to be smaller than $Y[m, n]$
    $Y[m, n] \lt \infty \Rightarrow$  all elements in last row need to smaller than $\infty$. 
    All other elements need to be smaller than the last element in their column.
    $\therefore$ all elements are smaller than $\infty\Rightarrow Y$ is full
    
#### c.  Give an algorithm to implement **EXTRACT-MIN** on a nonempty $m \times n$ Young tableau that runs in $O(m + n)$ time. Your algorithm should use a recursive subroutine that solves an $m \times n$ problem by recursively solving either an $(m - 1) \times n$ or an $m \times (n - 1)$ subproblem. (Hint: Think about MAX-HEAPIFY.) Define $T(p)$, where $p = m + n$, to be the maximum running time of **EXTRACT-MIN** on any $m \times n$ Young tableau. Give and solve a recurrence for $T(p)$ that yields the $O(m + n)$ time bound.
<!-- 左上會最小，提出以後開始做類似heap sort pop的操作只是子節點是右邊和下面 -->
- Idea
    1. store Y[1, 1] (when i=1, j=1)
    2. compare Y[i, j+1] and Y[i+1, j]
    3. let Y[i,j] = the smaller one
    4. recursive 2. and 3.
- Pseudo Code
~~~
func Extract_min(i, j): void
    temp <- Y[i][j]
    if(i == m && j == n)
        Y[i][j] = infinity
        return temp
    else 
        if(Y[i+1][j] < Y[i][j+1])
            Y[i][j] = Extract_min(i+1, j)
        else 
            Y[i][j] = Extract_min(i, j+1)
    return temp
end func
~~~
- Time Complexity
    $T(p) = T(p-1) + O(1) = T(p-2) + O(2) =\dots = O(p)$
#### d. Show how to insert a new element into a non-full $m \times n$ Young tableau in $O(m + n)$ time.
<!-- heap 的insert操作 -->
- Idea 
    1. put the new element in Y[m][n]
    2. compare Y[m][n] with Y[m-1][n] and Y[m][n-1]
    3. if Y[m][n] is smaller than Y[m-1][n] or Y[m][n-1], exchange the element
    4. loop 2. and 3.

- Pseudo Code
~~~
func Insert(k):void
    k <- input
    Y[m][n]= k
    while (m != 1 || n != 1)
        if(Y[m][n] < Y[m-1][n])
            exchange Y[m][n] <-> Y[m-1][n]
            if(m!=1)
                m = m-1
        else if (Y[m][n] < Y[m][n-1])
            exchange Y[m][n] <-> Y[m][n-1]
            if(n!=1)
                n = n-1
        else
            break
end func
~~~
- Time Complexity
    Because compare m+n times, time complexity is $O(m+n)$.
#### e. Using no other sorting method as a subroutine, show how to use an $n \times n$ Young tableau to sort $n^2$ numbers in $O(n^3)$ time.
<!-- 做c做的事情n^2次每次是2n(原本是n+m但題目變成長寬都是n所以是2n)所以是O(2n^3)=O(n^3) -->
- Idea
    Using same idea of (c\), but we have to insert $n^2$ elements.
- Pseudo Code
~~~
func Insert(k):void
    Y[n1][n2]= k
    while (n1 != 1 || n2 != 1)
        if(Y[n1][n2] < Y[n1-1][n2])
            exchange Y[n1][n2] <-> Y[n1-1][n2]
            if(n1!=1)
                n1 = n1-1
        else if (Y[n1][n2] < Y[n1][n2-1])
            exchange Y[n1][n2] <-> Y[n1][n2-1]
            if(n2!=1)
                n2 = n2-1
        else
            break
end func

func sort(): void
    arr[] <- input
    for(i=0;i<arr.size;i++)
        Insert(arr[i])
end func    
~~~
- Time Complexity
    Because need to insert $n^2$ elements, time complexity is $O(n^3)$.
#### f. Give an $O(m + n)$-time algorithm to determine whether a given number is stored in a given $m \times n$ Young tableau.
<!-- 
從左下開始找
要找得比較大就向又
反之就向上?
這題我不太確定這樣是對的應該啦
 -->
- Idea
    - start from Y[m][1]
    - loop
        1. compare with Y[i][j]
        2. larger: j+1
        3. smaller: i-1
- Pseudo Code
~~~
func findnum():bool
    key <- the number need to find
    i <- m
    j <- 1
    while(i!=1 || j!=n)
        if(key == Y[i][j])
            return true
        else if(key > Y[i][j])
            if(j==n)
                return false
            else
                j = j+1
        else if(i==1)
            return false
        else
            i = i-1
     return false   
end func
~~~
- Time Complexity
    In worst case, it will compare m+n times so time complexity is $O(m+n)$.

<!--
參考
https://walkccc-me.translate.goog/CLRS/Chap06/Problems/6-3/?_x_tr_sl=en&_x_tr_tl=zh-TW&_x_tr_hl=zh-TW&_x_tr_pto=op,sc
-->