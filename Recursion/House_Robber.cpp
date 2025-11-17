Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
  Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.



  class Solution {
public:
    int solve(vector<int>& nums, int i) {
        // Base case
        if (i >= nums.size()) return 0;

        // Option 1: Rob current house → move to i+2
        int rob = nums[i] + solve(nums, i + 2);

        // Option 2: Skip current house → move to i+1
        int skip = solve(nums, i + 1);

        // Return maximum money
        return max(rob, skip);
    }

    int rob(vector<int>& nums) {
        return solve(nums, 0);
    }
};
