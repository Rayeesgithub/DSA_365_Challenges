//https://leetcode.com/problems/fibonacci-number/submissions/1290642218/
// Recursive approach->     Time Complexity: O(2^N)  && Space Complexity: O(N)
int fibonacci(int N){
// Base Condition.
   if(N <= 1)  
    return N; 
return fib(n-1)+fib(n-2);
}

// optimal approach->   Time Complexity:0(N) &&  Space Complexity:0(1)
int fib(int n) {
  if (n == 0 || n == 1) {
        return n;
    }
    // Initialize the first two Fibonacci numbers
    int last = 1;        // This represents fib(1)
    int secondlast = 0;  // This represents fib(0)
    int ans;             // This will store the Fibonacci number being computed

    // Loop from 2 to n to calculate the nth Fibonacci number
    for (int i = 2; i <= n; i++) {
        // The current Fibonacci number is the sum of the last two
        ans = last + secondlast;

        // Update secondlast and last for the next iteration
        secondlast = last; // The current last becomes the second last
        last = ans;        // The current answer becomes the last
    }

    // Return the nth Fibonacci number
    return ans;
}
