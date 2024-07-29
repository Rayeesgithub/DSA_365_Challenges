https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/
// striver sheet

int minAddToMakeValid(string s) {
    stack<char> st; // Stack to keep track of unmatched parentheses
    
    // Iterate through each character in the string
    for(char ch : s) {
        if(st.empty()) { // If the stack is empty, push the current character
            st.push(ch);
        }
        else {
            char temp = st.top(); // Get the top element of the stack
            if(ch == ')' && temp == '(') { // If there's a matching pair of parentheses
                st.pop(); // Pop the top element from the stack
            }
            else {
                st.push(ch); // Otherwise, push the current character to the stack
            }
        }
    }
    return st.size(); // The size of the stack represents the number of unmatched parentheses
}
