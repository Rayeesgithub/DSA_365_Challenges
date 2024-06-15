//https://leetcode.com/problems/valid-palindrome/description/
bool isPalindrome(string s) { 
    int start = 0; 
    int end = s.length() - 1;

    // If the string is empty, it is considered a palindrome
    if(s.empty()) return true;

    // Loop until the two pointers meet in the middle
    while(start < end) {
        // Move the start pointer forward if the current character is not alphanumeric
        if(!isalnum(s[start])) {
            start++;
        }
        // Move the end pointer backward if the current character is not alphanumeric
        else if(!isalnum(s[end])) {
            end--;
        }
        // If the characters at the current pointers do not match when converted to lowercase, it's not a palindrome
        else if(tolower(s[start]) != tolower(s[end])) {
            return false;
        }
        // If the characters match, move both pointers towards the center
        else {
            start++;
            end--;
        }
    }
    // If all characters matched, the string is a palindrome
    return true;
