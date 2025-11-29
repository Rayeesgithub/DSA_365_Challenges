Example 1:
Input: X = 5
Output: 120
Explanation: 5! = 5*4*3*2*1


//approach1->  Time-0(N) , space=O(1)
int factorial(int X) {
    int ans = 1;                 // Store the final factorial value

    // Multiply all numbers from 1 to X
    for (int i = 1; i <= X; i++) {
        ans = ans * i;           // Keep updating ans
    }

    return ans;                  // Return factorial of X
}



//approach-2
Time= O(n)  Because function calls happen for every value from n → 0.
Space=O(n)  Due to recursive call stack
factorial(n)
 → factorial(n-1)
    → factorial(n-2)
       ...
          → factorial(0)



   
int factorial(int n) {
    if (n == 0) {          // Base case: factorial of 0 is 1
        return 1;
    }

    // Recursive case: n! = n × (n-1)!
    return n * factorial(n - 1);
}


