https://www.geeksforgeeks.org/problems/count-palindromic-subsequences/1

//striver sheet
#include <string>
using namespace std;

bool isPalindrome(int i, int j, string &s)     {
    while (i <= j) {
        if (s[i] != s[j]) {
            return false;
        } else {
            i++; 
            j--;
        }
    }
    return true;
}

long long int countPS(string str) {
    long long int count = 0; // Use long long int for the count variable as well
    int n = str.length();
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // Check if the substring str[i:j+1] is a palindrome
            if (isPalindrome(i, j, str)) {
                count++;
            }
        }
    }
    
    return count;
}
