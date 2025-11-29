//https://leetcode.com/problems/fibonacci-number/submissions/1290642218/
Example 1:
Input: N = 5
Output: 0 1 1 2 3 5
Explanation: 0 1 1 2 3 5 is the fibonacci series up to 5th term.(0 based indexing

// Recursive approach->     Time Complexity: O(2^N)  && Space Complexity: O(N)
int fibonacci(int N){
// Base Condition.
   if(N <= 1)  
    return N; 
return fib(n-1)+fib(n-2);
}




// optimal approach->   Time Complexity:0(N) &&  Space Complexity:0(1)
int fib(int n) {
    // Base cases: Fib(0) = 0, Fib(1) = 1
    if (n == 0 || n == 1) {
        return n;
    }

    int last = 1;        // Fib(1)
    int secondlast = 0;  // Fib(0)
    int ans;             // To store current Fibonacci value
 
    // Loop from 2 to n to build Fibonacci numbers
    for (int i = 2; i <= n; i++) {

        ans = last + secondlast;   // Current Fibonacci = previous two numbers

        secondlast = last;         // Move last → secondlast
        last = ans;                // Update last → current answer
    }

    return ans;   // Return nth Fibonacci number
}


Example for n = 5:

0, 1, 1, 2, 3, 5
