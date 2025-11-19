Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]



  #include<bits/stdc++.h>
using namespace std;

// Function to generate all balanced parentheses
void generateParenthsis(vector<string>& ans, int open, int close, string output){

    // BASE CASE: when no brackets left to place
    if(open == 0 && close == 0){
        ans.push_back(output);   // store the valid string
        return;
    }

    // CASE 1: You can always add '(' if any open bracket is left
    if(open > 0){
        output.push_back('(');   // choose '('
        generateParenthsis(ans, open - 1, close, output);  // recurse
        output.pop_back();       // backtrack (undo choice)
    }

    // CASE 2: You can add ')' only when close > open
    // (means more ')' are allowed only if '(' already placed)
    if(close > open){
        output.push_back(')');   // choose ')'
        generateParenthsis(ans, open, close - 1, output);  // recurse
        // no need to pop_back here because output is local copy
    }
}

int main() {

    int n = 3;              // total pairs of parentheses
    int open = n;           // number of '(' left to place
    int close = n;          // number of ')' left to place
    
    vector<string> ans;     // store all valid combinations
    string output = "";     // temporary string used during generation

    generateParenthsis(ans, open, close, output);

    // Print all generated balanced parentheses
    for(auto it : ans){
        cout << it << " ";
    }
}
