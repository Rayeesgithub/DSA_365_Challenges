https://leetcode.com/problems/remove-outermost-parentheses/description/
// striver

Input: s = "(()())(())"
Output: "()()()"


  string removeOuterParentheses(string s) {
    
    string ans = "";   // Ans string to store final result without outer parentheses
    int balance = 0;   // This keeps track of how deep we are inside parentheses
    
    // Loop through each character of the string
    for(int i = 0; i < s.size(); i++) {
        
        // If current character is '('
        if(s[i] == '(') {
            
            // If balance > 0, it means we are NOT at the outermost level,
            // so we can safely include this '(' into the result
            if(balance > 0) {
                ans += s[i];
            }
            
            // Increase depth (we entered one more '(' )
            balance++;
        }
        else { // Current character is ')'
            
            // First decrease depth (because this ')' closes one '(')
            balance--;
            
            // If balance > 0 now, it means this ')' is not outermost,
            // so add it to the answer
            if(balance > 0) {
                ans += s[i];
            }
        }
    }
    
  
    return ans;
}



Dry run->

s = "(()())(())"

  | i | s[i] | Condition         | balence change | balence | Added to ans | ans result |
| - | ---- | ----------------- | -------------- | ------- | ------------ | ---------- |
| 0 | (    | balence > 0 ? No  | ++             | 1       | No           | ""         |
| 1 | (    | balence > 0 ? Yes | ++             | 2       | (            | "("        |
| 2 | )    | --                | 1              | Yes     | )            | "()"       |
| 3 | (    | balence > 0 ? Yes | ++             | 2       | (            | "()("      |
| 4 | )    | --                | 1              | Yes     | )            | "()()"     |
| 5 | )    | --                | 0              | No      | ❌            | "()()"     |
| 6 | (    | balence > 0 ? No  | ++             | 1       | No           | "()()"     |
| 7 | (    | balence > 0 ? Yes | ++             | 2       | (            | "()()("    |
| 8 | )    | --                | 1              | Yes     | )            | "()()()"   |
| 9 | )    | --                | 0              | No      | ❌            | "()()()"   |


