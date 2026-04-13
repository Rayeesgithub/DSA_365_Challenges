//https://leetcode.com/problems/reverse-words-in-a-string/description/
// striver sheet
Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
broute force

void solve(string &str){
    stack<string> st;

    string temp = "";
 for(int i = 0; i < str.size(); i++){

        if(str[i] == ' '){
            if(!temp.empty()){
                st.push(temp);
                temp = "";
            } }
        else{
            temp += str[i];
        }
    }
    // last word
    if(!temp.empty()){
        st.push(temp);
    }
 // print in reverse order
    while(!st.empty()){
        cout << st.top();
        st.pop();

        if(!st.empty()) cout << " ";  // avoid extra space
    }
}


📌 How it works behind the scene?
Input	" i love you "
Extract words	i, love, you
Stack (top → bottom)	you → love → i
Pop + Build	"you love i"

Time:
👉 O(n) — traverse string once

Space:
👉 O(n) — stack stores words

 


string reverseWords(string s) {
    
    // Input:
    // s = "welcome to the jungle"

    stringstream ss(s);
    vector<string> words;
    string word;

    // Step 1: Extract words
    while(ss >> word){
        // Iteration 1 → word = "welcome"
        // words = ["welcome"]

        // Iteration 2 → word = "to"
        // words = ["welcome", "to"]

        // Iteration 3 → word = "the"
        // words = ["welcome", "to", "the"]

        // Iteration 4 → word = "jungle"
        // words = ["welcome", "to", "the", "jungle"]

        words.push_back(word);
    }

    // Step 2: Reverse words
    reverse(words.begin(), words.end());

    // words = ["jungle", "the", "to", "welcome"]

    // Step 3: Join words
    string result = "";

    for(string w : words){
        // Iteration 1 → result = "jungle "
        // Iteration 2 → result = "jungle the "
        // Iteration 3 → result = "jungle the to "
        // Iteration 4 → result = "jungle the to welcome "

        result += w + " ";
    }

    // Remove last extra space
    result.pop_back();

    // Final result = "jungle the to welcome"

    return result;
}
