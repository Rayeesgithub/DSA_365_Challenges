Example 1:
Input: n=6
Output: 6 is a perfect number

the sum of their proper divisors (1+2+3) 



  // Time Complexity = O(n), Space Complexity = O(1)
  
  bool isPerfect(int n) {

    // Stores the sum of *proper divisors* (divisors excluding the number itself)
    int sum = 0;

    // Loop runs from 1 to n-1 to check all possible divisors
    for (int i = 1; i <= n - 1; i++) {

        // If i divides n perfectly (no remainder)
        if (n % i == 0)
            sum = sum + i;   // Add divisor to the sum
    }

    // A number is Perfect if sum of its proper divisors equals the number
    if (sum == n)
        return true;        // n is a Perfect Number
    else
        return false;       // n is NOT Perfect
}
