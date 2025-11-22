https://leetcode.com/problems/longest-palindromic-substring/description/
//striver sheet

Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
    Input: s = "cbbd"
Output: "bb"

time complexity is O(n^2) * O(n) = O(n^3)  space complexity is O(1)
// Helper function to check if substring s[i...j] is a palindrome
bool isPalindrome(string str, int i, int j) {

    // Use two-pointer technique: check from both ends
    while(i <= j) {

        // If mismatch found → not a palindrome
        if(str[i] != str[j]) {
            return false;
        }
        i++; 
        j--;
    }

    // If entire substring matched → palindrome
    return true;
}

string longestPalindrome(string s) {
    string ans = ""; // To store the longest palindrome found

    // Outer loop: choose starting index of substring
    for(int i = 0; i < s.size(); i++) {

        // Inner loop: choose ending index of substring
        for(int j = i; j < s.size(); j++) {

            // Check if substring s[i...j] is palindrome
            if(isPalindrome(s, i, j)) {

                // Extract substring (j-i+1 length)
                string t = s.substr(i, j - i + 1);

                // Update ans if new substring is longer
                ans = t.size() > ans.size() ? t : ans;
            }
        }
    }

    // Return the longest palindrome found
    return ans;
}

