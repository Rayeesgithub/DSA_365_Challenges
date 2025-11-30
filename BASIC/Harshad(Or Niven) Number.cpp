Example 1:
Input: 378
Output: Yes it is a Harshad number.
Explanation: 3+7+8=18. 378 is divisible by 18. Therefore 378 is a harshad number.

  Time=0(n) space=(1)

  #include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 378;    // Number to check if it's a Harshad number
    int temp = n;   // Temporary variable to extract digits
    int sum = 0;    // Variable to store the sum of digits

    // Loop to calculate the sum of digits of the number
    while (temp != 0) {
        sum += temp % 10;  // Add the last digit of the number to the sum
        temp /= 10;        // Remove the last digit from the number
    }

    // Check if the number is divisible by the sum of its digits
    if (n % sum == 0) {
        cout << "YES it is Harshad Number" << "\n";  // It is a Harshad number
    }
    else {
        cout << "NO it is not Harshad Number" << "\n";  // It is not a Harshad number
    }
}
