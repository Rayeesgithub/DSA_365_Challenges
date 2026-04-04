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
            }
        }
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

 


#include<bits/stdc++.h>
using namespace std;

void solve(string &s){

    // Step 1: reverse whole string
    reverse(s.begin(), s.end());

    int start = 0;

    // Step 2: reverse each word
    for(int i = 0; i <= s.size(); i++){

        if(i == s.size() || s[i] == ' '){
            reverse(s.begin() + start, s.begin() + i);
            start = i + 1;
        }
    }

    cout << s;
}

⏱️ Complexity
Time: O(n)
Space: O(1) ✅ (best)
