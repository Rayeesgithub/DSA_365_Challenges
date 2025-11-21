https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/

Input: s = "abbaca"
Output: "ca"
Explanation: For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.
    The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".

string removeDuplicates(string s) {
        string ans = ""; // This will store result after removing duplicates

        // Loop through each character of input string
        for(int i = 0; i < s.size(); i++) {

            // Check if ans already has some characters
            if(ans.size() > 0) {

                // Compare current char of s with last char of ans
                // If both are same → remove last char (pop) → duplicate removed
                if(ans[ans.size() - 1] == s[i]) {
                    ans.pop_back(); // remove the duplicate character
                }
                else {
                    ans.push_back(s[i]); // add current character to ans
                }
            }
            else {
                // If ans is empty, directly push character
                ans.push_back(s[i]);
            }
        }

        return ans; // return final string after removing duplicates
}
