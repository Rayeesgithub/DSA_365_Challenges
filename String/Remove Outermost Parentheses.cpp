https://leetcode.com/problems/remove-outermost-parentheses/description/
// striver

   string removeOuterParentheses(string s) {
        string ans=""; int balence=0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='('){
                if(balence>0){
                    ans+=s[i];
                }
                balence++;
            }
            else{
                balence--;
                if(balence>0)
                ans+=s[i];
            }
        }
        return ans;
    }
