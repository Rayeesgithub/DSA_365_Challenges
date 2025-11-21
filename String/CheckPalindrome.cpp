Problem-> gfg & leetcode

Input: s = "abba"
Output: true
Explanation: "abba" reads the same forwards and backwards, so it is a palindrome.
Input: s = "abc" 
Output: false

    
#include<bits/stdc++.h>
using namespace std;
✅ Approach 1: Two-Pointer Method

bool isPalindrome(string& s) {
    // Initialize two pointers:
    // left → start of string
    // right → end of string
    int left = 0;
    int right = s.size() - 1;

    // Run loop until both pointers cross each other
    while(left <= right) {

        // If characters at both ends are not same,
        // then the string is NOT a palindrome
        if(s[left] != s[right]) {
            return false;
        }

        // Move left pointer forward and right pointer backward
        left++;
        right--;
    }

    // If loop completes, all characters matched -> palindrome
    return true;
}

✅ Approach 2: Reverse and Compare
 bool isPalindrome(string& s) {
    // Store the original string
    string orignal = s;

    // Reverse the string using STL reverse()
    reverse(s.begin(), s.end());

    // If reversed string is different from original,
    // then it is NOT a palindrome
    if(s != orignal) {
        return false;
    }

    // Otherwise it's a palindrome
    return true;
}

int main(){
    int t;
    cin>>t;
    while(t--){
    string s;
    cout<<"enter the Any String :";
    cin>>s;
    if(checkPalindrome(s)){
        cout<<"Palindrome"<<endl;
    }
    else{
        cout<<"this is Not Palindrome"<<endl;
    }
    }
}
