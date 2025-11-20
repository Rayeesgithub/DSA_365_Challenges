Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.



  #include<bits/stdc++.h>
using namespace std;

// Function to find all combinations whose sum = target
// arr  → input array
// ans  → stores all valid combinations
// output → current combination being built
// index → current index in array
// target → remaining sum we need to achieve
void CombinationalSum(vector<int>& arr, vector<vector<int>>& ans,
                      vector<int> output, int index, int target) {

    // BASE CASE:
    // If we have checked all elements
    if(index >= arr.size()) {

        // If target becomes 0 → valid combination found
        if(target == 0) {
            ans.push_back(output);
        }
        return;
    }

    // INCLUDE CASE:
    // If current number is <= target,
    // then we can include arr[index]
    if(arr[index] <= target) {
        
        // Add element to current combination
        output.push_back(arr[index]);

        // Recurse with same index (because repetition allowed)
        // Reduce target by arr[index]
        CombinationalSum(arr, ans, output, index, target - arr[index]);

        // Backtrack (remove last added element)
        output.pop_back();
    }

    // EXCLUDE CASE:
    // Move to next index (not including current number)
    CombinationalSum(arr, ans, output, index + 1, target);
}


int main() {

    vector<int> arr = {2, 3, 5};
    int target = 8;

    vector<vector<int>> ans;   // Stores all valid combinations
    vector<int> output;        // Stores one combination at a time

    int index = 0;

    // Call the recursive function
    CombinationalSum(arr, ans, output, index, target);

    // Print all combinations
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
