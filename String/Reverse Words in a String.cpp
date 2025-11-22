//https://leetcode.com/problems/reverse-words-in-a-string/description/
// striver sheet
Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
broute force

string reverseWords(string s) {
    stack<string> st;
    string word = "";

    // Step 1: Extract words and push to stack
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != ' ') {
            word += s[i];  // build current word
        } 
        else {
            if(word != "") { // if a word is formed
                st.push(word);
                word = "";   // reset for next word
            }
        }
    }

    // Push last word (if available)
    if(word != "") st.push(word);

    // Step 2: Pop from stack and form result
    string res = "";
    while(!st.empty()) {
        res += st.top();
        st.pop();
        if(!st.empty()) res += " "; // add space between words
    }

    return res;
}



📌 How it works behind the scene?
Input	" i love you "
Extract words	i, love, you
Stack (top → bottom)	you → love → i
Pop + Build	"you love i"



 

class Solution {
public:
    string reverseWords(string s) {

        int left = 0; 
        int right = s.size() - 1;

        string temp = "";  // will store a single word while scanning
        string ans = "";   // final reversed result

        // Step 1 → Traverse the string from left to right
        while (left <= right) {

            char ch = s[left];  // take current character

            // If character is NOT space → build the current word
            if (ch != ' ') {
                temp += ch;
            }
            // If space is found AND temp has a word → add it into ans (reversed order)
            else if (ch == ' ' && !temp.empty()) {

                // If ans already has words → insert current word before ans
                // so that order becomes reversed
                if (!ans.empty()) 
                    ans = temp + " " + ans;
                else 
                    ans = temp;  // First word goes directly

                temp = ""; // reset for next word
            }
            left++;
        }

        // Step 2 → For the last stored word (if not followed by space)
        if (!temp.empty()) {
            if (!ans.empty()) 
                ans = temp + " " + ans;
            else 
                ans = temp;
        }

        return ans;
    }
};
