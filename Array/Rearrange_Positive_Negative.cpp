//https://leetcode.com/problems/rearrange-array-elements-by-sign/


Example 1:
Input:
arr[] = {1,2,-4,-5}, N = 4
Output:
1 -4 2 -5
Explanation: 
Positive elements = 1,2
Negative elements = -4,-5

    
// approach1 Time=0(n) && space=0(n)
// Approach 1: Brute Force
// Time Complexity = O(N)
// Space Complexity = O(N)

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        vector<int> ans;          // Final result array
        vector<int> positive;     // Store all positive numbers
        vector<int> negative;     // Store all negative numbers

        // Step 1: Separate positive and negative elements
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0)
                positive.push_back(nums[i]);
            else
                negative.push_back(nums[i]);
        }

        // Step 2: Merge them alternately → pos, neg, pos, neg...
        int pos = 0, neg = 0;

        for (int i = 0; i < nums.size(); i++) {

            // Even index → positive number
            if (i % 2 == 0) {
                ans.push_back(positive[pos++]);
            }

            // Odd index → negative number
            else {
                ans.push_back(negative[neg++]);
            }
        }

        return ans;
    }
};




      
//optimized approach
// Optimized Approach
// Time Complexity = O(N)
// Space Complexity = O(N)

class Solution {
public:
vector<int> rearrangeArray(vector<int>& nums) {

vector<int> ans(nums.size(), 0);  // Pre-allocated result array

        int pos = 0; // Even index position → for positive numbers
        int neg = 1; // Odd index position → for negative numbers

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] > 0) {
                // Place positive number at even index
                ans[pos] = nums[i];
                pos += 2;              // Move to next even index
            }

            else {
                // Place negative number at odd index
                ans[neg] = nums[i];
                neg += 2;              // Move to next odd index
            }
        }

        return ans;
    }
};
