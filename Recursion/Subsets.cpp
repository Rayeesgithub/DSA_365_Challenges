// striver 

 void findSubseq(vector<int>& s, vector<int> output, int i, vector<vector<int>>& result) {
    // Base case: If we have processed all elements of the vector
    if (i == s.size()) {
        result.push_back(output);  // Add the generated subsequence to the result
        return;
    }

    // Exclude the current element and move forward
    findSubseq(s, output, i + 1, result);

    // Include the current element and move forward
    output.push_back(s[i]);
    findSubseq(s, output, i + 1, result);
}

vector<vector<int>> subsets(vector<int>& s) {
    vector<vector<int>> result;  // To store all subsets
    vector<int> output;          // To store the current subset
    findSubseq(s, output, 0, result);  // Generate all subsets using recursion
    sort(result.begin(), result.end());  // Sort the result (optional)
    return result;
}
