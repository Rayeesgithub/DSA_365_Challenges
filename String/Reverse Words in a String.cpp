//https://leetcode.com/problems/reverse-words-in-a-string/description/
// striver

broute force

 string reverseWords(string s) {
         stack<string> st;  // Stack to hold words
    string str = "";   // Temporary string to build each word
    
    // Iterate through each character in the string
    for (int i = 0; i < s.length(); i++) {
        if   (s[i] == ' ') { // If a space is encountered, a word is completed
          if (!str.empty()) { // Push only non-empty words to the stack
                st.push(str);
                str = ""; // Reset the string to start a new word
            }
        } else {
            str += s[i]; // Append the current character to the word
        }
    }

    // Push the last word onto the stack if it exists
    if (!str.empty()) {
        st.push(str);
    }

    string ans = ""; // String to store the result

    // Pop words from the stack and form the reversed words string
    while (!st.empty()) {
        ans += st.top(); // Append the top word from the stack to the result
        st.pop(); // Remove the top word from the stack
        if (!st.empty()) { // Add a space if there are more words to add
            ans += " ";
        }
    }
    return ans;
        
    }


//optimal approach
