https://leetcode.com/problems/longest-palindromic-substring/description/
//striver sheet


time complexity is O(n^2) * O(n) = O(n^3)  space complexity is O(1)
bool isPalindrome(int i, int j, string &s) {
    // Continue checking while the start index is less than or equal to the end index
    while (i <= j) {
        // If the characters at the start and end indices do not match, it's not a palindrome
        if (s[i] != s[j]) {
            return false;
        } else {
            // Move towards the center
            i++;
            j--;
        }
    }
    // If all characters matched, it's a palindrome
    return true;
}

// Function to find the longest palindromic substring in the input string s
string longestPalindrome(string s) {
    string ans = ""; // Variable to store the longest palindromic substring

    // Iterate over all possible starting indices of substrings
    for (int i = 0; i < s.length(); i++) {
        // Iterate over all possible ending indices of substrings
        for (int j = i; j < s.length(); j++) {
            // Check if the substring s[i:j] is a palindrome
            if (isPalindrome(i, j, s)) {
                // Get the current palindromic substring
                string t = s.substr(i, j - i + 1);
                // Update ans if the current palindromic substring is longer than the previous longest
                ans = t.size() > ans.size() ? t : ans;
            }
        }
    }
    // Return the longest palindromic substring found
    return ans;
