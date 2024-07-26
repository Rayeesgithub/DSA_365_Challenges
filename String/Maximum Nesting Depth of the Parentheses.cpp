https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/
// striver sheet

int maxDepth(string s) {
    int count = 0; // Counter for current depth of parentheses.
    int maxDepth = 0; // To store the maximum depth encountered.
    
    // Iterate through each character in the string.
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            count++; // Increment depth counter when an opening parenthesis is encountered.
            if (count > maxDepth) {
                maxDepth = count; // Update the maximum depth if current depth is greater.
            }
        } else if (s[i] == ')') {
            count--; // Decrement depth counter when a closing parenthesis is encountered.
        }
        // No need to reset count for operators and spaces.
    }
    
    // Return the maximum depth found.
    return maxDepth;
}
