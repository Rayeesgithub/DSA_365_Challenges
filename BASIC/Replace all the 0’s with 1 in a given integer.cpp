Input N = 102003 
Output 112113 
Explanation The 2nd, 4th, and 5th positions from the left contain 0. These 0s are replaced with 1s, resulting in 112113.

Time=0(n) space=0(1)
 int replaceZerosWithOnes(int N) {
        // Edge case: if the number is 0, return 1
        if (N == 0) return 1;

        // Variable to store the result in reverse order
        int reversed = 0;

        // Loop through each digit of the number
        while (N > 0) {
            // Extract the last digit
            int digit = N % 10;

            // If digit is 0, convert it to 1
            if (digit == 0) digit = 1;

            // Build reversed number
            reversed = reversed * 10 + digit;

            // Remove last digit from original number
            N /= 10;
        }

        // Variable to store the final result after reversing
        int result = 0;

        // Reverse the number again to restore original order
        while (reversed > 0) {
            result = result * 10 + (reversed % 10);
            reversed /= 10;
        }

        return result;
    }
