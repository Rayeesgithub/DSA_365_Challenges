Given a string s, return true if the s can be palindrome after deleting at most one character from it.
Example 2:
Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
Example 3:

Input: s = "abc"
Output: false


// Function to check if substring s[left...right] is a palindrome
bool checkPalindrome(string &s, int left, int right) {

    // Move pointers inward while checking characters
    while(left <= right) {
        // If mismatch found → not a palindrome
        if(s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }

    // If fully matched → palindrome
    return true;
}

bool validPalindrome(string s) {
    int left = 0;
    int right = s.size() - 1;

    // Two pointer check like normal palindrome
    while(left <= right) {

        // A mismatch occurs
        if(s[left] != s[right]) {

            // We try removing one char from either left or right
            // If any one becomes palindrome → return true
            return checkPalindrome(s, left + 1, right) || 
                   checkPalindrome(s, left, right - 1);
        }

        // If matched, move both pointers
       else{
                left++;
                right--;
            }
    }

    // If loop ends without mismatch → string already a palindrome
    return true;
}
