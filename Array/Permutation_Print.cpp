// https://www.youtube.com/watch?v=f2ic2Rsc9pU&t=32s

class Solution {
public:

    // Recursive helper function to generate permutations
    void permut(int index, vector<int>& nums, vector<vector<int>>& ans) {
        // Base case: if index reaches end of array, add current permutation to result
        if (index == nums.size()) {
            ans.push_back(nums);  // push the current state of nums into ans
            return;
        }

        // Try placing every number at the current index
        for (int i = index; i < nums.size(); i++) {
            swap(nums[i], nums[index]);        // Swap current index with i to fix one element
            permut(index + 1, nums, ans);      // Recurse for the remaining part
            swap(nums[i], nums[index]);        // Backtrack: undo the swap to try next possibility
        }
    }

    // Main function called by user
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;  // Stores all permutations
        permut(0, nums, ans);     // Start permutation from index 0
        return ans;
    }
};
