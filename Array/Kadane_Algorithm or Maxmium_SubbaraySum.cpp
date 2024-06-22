//https://leetcode.com/problems/maximum-subarray/description/
// striver sheet

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Approach 1: Brute Force
        // Initialize the maximum sum to the smallest possible integer value
        int maxi = INT_MIN;
        int n = nums.size();
        // Iterate over each starting point of the subarray
        for (int i = 0; i < nums.size(); i++) {
            // Iterate over each ending point of the subarray starting from i
            for (int j = i; j < nums.size(); j++) {
                int sum = 0;
                // Calculate the sum of the subarray from index i to j
                for (int k = i; k <= j; k++) {
                    sum = sum + nums[k];
                }
                // Update the maximum sum found so far
                maxi = max(maxi, sum);
            }
        }
        // Return the maximum subarray sum found using brute force
        return maxi;
        
        
      // Approach 2: Better Approach (still O(n^2))
        // Iterate over each starting point of the subarray
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            // Iterate over each ending point of the subarray starting from i
            for (int j = i; j < nums.size(); j++) {
                // Add the current element to the sum
                sum = sum + nums[j];
                // Update the maximum sum found so far
                maxi = max(maxi, sum);
            }
        }
        // Return the maximum subarray sum found using the better approach
        return maxi;
        
       
      // Approach 3: Optimal Approach (Kadane's Algorithm)
        // Initialize the current sum to 0
        int sum = 0;
        // Iterate through the array
        for (int i = 0; i < n; i++) {
            // Add the current element to the sum
            sum = sum + nums[i];
            // Update the maximum sum found so far
            if (sum > maxi) 
                maxi = sum;
            // If the current sum is negative, reset it to 0
            if (sum < 0) 
                sum = 0;
        }
        // Return the maximum subarray sum found using Kadane's Algorithm
        return maxi;
    }
};
