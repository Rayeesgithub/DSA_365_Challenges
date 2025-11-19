Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = "2"
Output: ["a","b","c"]



#include<bits/stdc++.h>
using namespace std;

// Function to generate all possible letter combinations
void letterCombination(string &digits, vector<string>& ans, int index,
                       string output, vector<string>& mapping) {

    // If digits string is empty → no combinations possible
    if(digits.size() == 0) return;

    // BASE CASE: when we have processed all digits
    if(index >= digits.size()) {
        ans.push_back(output);  // store the completed string
        return;
    }

    // Convert current digit character → integer digit
    int digit = digits[index] - '0';

    // Get corresponding letters from mapping
    string value = mapping[digit];

    // Explore all letters mapped to the current digit
    for(int i = 0; i < value.size(); i++) {

        output.push_back(value[i]);  // choose a letter

        // Recur for next digit
        letterCombination(digits, ans, index + 1, output, mapping);

        output.pop_back();  // backtrack (undo the choice)
    }
}

int main() {
    string digits = "23";   // Input digits string
    vector<string> ans;     // To store final combinations
    string output = "";     // Temporary string used during generation
    int index = 0;          // Start from digit 0

    // Mapping each digit to its corresponding letters
    vector<string> mapping(10);
    mapping[2] = "abc";
    mapping[3] = "def";
    mapping[4] = "ghi";
    mapping[5] = "jkl";
    mapping[6] = "mno";
    mapping[7] = "pqrs";
    mapping[8] = "tuv";
    mapping[9] = "wxyz";

    // Start generating combinations
    letterCombination(digits, ans, index, output, mapping);

    // Print all letter combinations
    for(auto it : ans) {
        cout << it << " ";
    }
}
