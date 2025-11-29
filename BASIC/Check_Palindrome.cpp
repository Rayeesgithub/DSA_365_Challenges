//https://leetcode.com/problems/palindrome-number/

Example 1:
Input:N = 4554
Output:Palindrome Number
Explanation: The reverse of 4554 is 4554 and therefore it is palindrome number


Time-O(log₁₀(n)) &&
Space=O(1)
digit, ans, original → only few integer variables.No array or extra memory used.



#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 45541;        // Input number
    int original = n;     // Store original number to compare later
    int ans = 0;          // This will store the reversed number

    // Reverse the number
    while(n != 0){
        int digit = n % 10;      // Extract last digit
        ans = ans * 10 + digit;  // Build reversed number
        n = n / 10;              // Remove last digit from n
    }

    // Check if reversed number is equal to original number
    if(ans == original){
        cout << "this is Palindrome";
    }
    else{
        cout << "Not palindrome";
    }
}

