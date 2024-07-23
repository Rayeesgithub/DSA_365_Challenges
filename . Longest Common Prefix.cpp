//https://leetcode.com/problems/longest-common-prefix/description/
//striver sheet

//broute force
string longestCommonPrefix(vector<string>& strs) {
    // Sort the array of strings.
    sort(strs.begin(), strs.end());

    int n = strs.size(); // Get the number of strings.
    string ans = ""; // Initialize the result string for the longest common prefix.
    string first = strs[0]; // Get the first string in the sorted list.
    string last = strs[n - 1]; // Get the last string in the sorted list.

    // Compare characters of the first and last strings up to the length of the shorter one.
    for(int i = 0; i < min(first.size(), last.size()); i++) {
        // If characters match, add the character to the answer.
        if(first[i] == last[i]) {
            ans.push_back(first[i]); // Alternatively, ans += first[i];
        } 
        else {
            // If characters do not match, return the current answer as the longest common prefix.
            return ans;
        }
    } 
    // Return the answer if loop completes.
    return ans;
}
