Input: num = 529
Output:7
Explanation: In first iteration the digits sum will be = 5 + 2 + 9 => 16
In second iteration the digits sum will be 1 + 6 => 7.
Now single digit is remaining , so we return it. 

Time=O(n).
Space Complexity: O(1),


    int addDigits(int num) {
        // Loop until number has only one digit
        while (num >= 10) {
            // Initialize sum of digits to zero
            int sum = 0;

            // Extract each digit and add to sum
            while (num > 0) {
                // Add last digit to sum
                sum += num % 10;
                // Remove last digit from number
                num /= 10;
            }

            // Update number with the sum of digits
            num = sum;
        }
        // Return the single-digit number
        return num;
    }
