//https://leetcode.com/problems/longest-common-prefix/description/
Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

string longestCommonPrefix(vector<string>& strs) {

    // Step 1: Sort the list of strings in lexicographical (dictionary) order
    sort(strs.begin(), strs.end());
    // After sorting, strings with common prefix move closer together
    
    int n = strs.size();
    string ans = "";

    // Step 2: Compare only the FIRST and LAST strings after sorting
    // → They have the maximum possible difference
    // → The common prefix of these ensures prefix for ALL strings
    string first = strs[0];
    string last = strs[n-1];

    // Step 3: Check character-by-character until mismatch
    for(int i = 0; i < min(first.size(), last.size()); i++) {

        // If characters differ → stop
        if(first[i] != last[i]) {
            break;
        }
        else {
            // If characters match → it is part of the prefix
            ans.push_back(first[i]);
        }
    }

    // Return the longest common prefix
    return ans;
}

📌 Total Time Complexity = O(N log N + M)
📌 Space Complexity = O(1) (ignoring input storage)
