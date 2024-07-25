https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/
// love Babbar

string removeDuplicates(string s) {
    // Initialize an empty string to store the result
    string ans = "";

    // Iterate through each character in the input string `s`
    for (int i = 0; i < s.length(); i++) {
        // Check if `ans` is not empty and the last character of `ans` is the same as the current character in `s`
        if (ans.length() > 0 && ans[ans.length() - 1] == s[i]) {
            // If the condition is true, remove the last character from `ans` (pop it off)
            ans.pop_back();
        } else {
            // If the condition is false, add the current character from `s` to `ans` (push it on)
            ans.push_back(s[i]);
        }
    }

    // Return the modified string `ans` after removing adjacent duplicates
    return ans;
}
