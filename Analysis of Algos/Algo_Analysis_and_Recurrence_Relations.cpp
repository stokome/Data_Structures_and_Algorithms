//Asymtotic analysis- In asysmtotic analysis we evaluate alogirithm in terms of input size of the data.

//We can have three cases to analyze an algorithm: 
//1) The Worst Case - We calculate the upper-bound on running time of the algorithm. In most situation we perform worst case analysis
//2) Average Case- In average case scenario we summation of running time for all inputs and then divide by numbe rof inputs to find the average
//3) Best Case- We calculate the lower bound on the runing time of the algorithm.

//Asymtotic Notations- Asymtotic notations are mathmticle tools to represent time complexity of algos for asymtotic analysis.
//There are three tpyes of asymtotic notations-
//1.Big_Theta Notations - It is the exact asymtotic behaviour of the algo/funciton.
//2. Big_O Notation - It is the asymtotic upper bound of the algo/funciton.
//3. Big_Omega Notation - It is the asymtotic lower bound of the algo/function



//Recurrence Relation - Finding the time complexity of a recursion
//Ways to solve recurrence relation- 
//1. Substitution- We make a guess for the solution and then we use mathematical induction to prove the guess is correct or incorrect. 
/**
    For example consider the recurrence T(n) = 2T(n/2) + n

        We guess the solution as T(n) = O(nLogn). Now we use induction
        to prove our guess.

        We need to prove that T(n) <= cnLogn. We can assume that it is true
        for values smaller than n.

        T(n) = 2T(n/2) + n
            <= 2cn/2Log(n/2) + n
            =  cnLogn - cnLog2 + n
            =  cnLogn - cn + n
            <= cnLogn
**/
//2. Recurence Tree Method -  In this method, we draw a recurrence tree and calculate the time taken by every level of tree. Finally,we    sum the work done at all levels.
/**
 For example consider the recurrence relation 
T(n) = T(n/4) + T(n/2) + cn^2

           cn^2
         /      \
     T(n/4)     T(n/2)

If we further break down the expression T(n/4) and T(n/2), 
we get following recursion tree.

                cn^2
           /           \      
       c(cn^2)/16      c(cn^2)/4
      /      \          /     \
  T(n/16)     T(n/8)  T(n/8)    T(n/4) 
Breaking down further gives us following
                 cn^2
            /            \      
       c(cn^2)/16          c(cn^2)/4
       /      \            /      \
c(cn^2)/256   c(cn^2)/64  c(cn^2)/64    c(cn^2)/16
 /    \      /    \    /    \       /    \  

To know the value of T(n), we need to calculate sum of tree 
nodes level by level. If we sum the above tree level by level, 
we get the following series
T(n)  = c(n^2 + 5(n^2)/16 + 25(n^2)/256) + ....
The above series is geometrical progression with ratio 5/16.

To get an upper bound, we can sum the infinite series. 
We get the sum as (cn^2)/(1 - 5/16) which is O(cn^2)
**/

//3. Master Method - Master method is a direct way to ge to the soluiton.
//Master Method is only applicable for the following eq- aT(n/b) + f(n) where a>=1 and b>1
/**
 Here we have following three cases -There are following three cases: 
1. If f(n) = O(n^c) where c < Log(b)a then T(n) = Θ(nLog(b)a) 

2. If f(n) = Θ(n^c) where c = Log(b)a then T(n) = Θ(n^c * Log n) 

3.If f(n) = Ω(n^c) where c > Log(b)a then T(n) = Θ(f(n))

Examples of some standard algorithms whose time complexity can be evaluated using Master Method 
Merge Sort: 
T(n) = 2T(n/2) + Θ(n). It falls in case 2 as c is 1 and Log(b)a] is also 1. So the solution is Θ(nLogn) 

Binary Search: T(n) = T(n/2) + Θ(1). It also falls in case 2 as c is 0 and Log(b)a is also 0. So the solution is Θ(Logn) 
 */


//Amortized analysis is used where occasional operation is very slow but most of the other operations are very fast.In Amortized Analysis, we analyze a sequence of operations and guarantee a worst case average time which is lower than the worst case time of a particular expensive operation. 
//Amortized analysis is used to consider the overall effects of the set of multiple operations.