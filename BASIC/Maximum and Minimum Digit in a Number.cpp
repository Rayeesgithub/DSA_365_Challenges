Input: N = 2746
Output: Largest digit: 7, Smallest digit: 2
Explanation: 
Largest digit in N is 7 whereras smallest digit is 2.

Input: N = 23004
Output: Largest digit : 4, Smallest digit : 0

Time->➡ O(log n) space0(1)



  // approach 1
  #include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 2746;

    int maxi = -1;      // Will store the maximum digit
    int mini = 9999;    // Will store the minimum digit

    // Loop runs until all digits of n are processed
    while (n > 0) {

        int digit = n % 10;   // Extract last digit

        maxi = max(maxi, digit);  // Update maximum digit found so far
        mini = min(mini, digit);  // Update minimum digit found so far

        n = n / 10;   // Remove the last digit
    }

    cout << maxi << " " << mini;
}

// approach2

 void findMaxMinDigit(int n) {
        // Initialize max and min digits
        int maxDigit = 0;
        int minDigit = 9;

        // Traverse digits one by one
        while (n > 0) {
            // Extract last digit
            int digit = n % 10;

            // Update max digit
            if (digit > maxDigit) maxDigit = digit;

            // Update min digit
            if (digit < minDigit) minDigit = digit;

            // Remove last digit
            n = n / 10;
        }

        // Print result
        cout << "Max Digit: " << maxDigit << endl;
        cout << "Min Digit: " << minDigit << endl;
    }
