//https://leetcode.com/problems/subarray-sum-equals-k/description/
//striversheet

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Brute force approach 
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0; 
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j]; // Add the current element to the sum
                if (sum == k) { // If the sum equals k, increment the count
                    count++;
                }
            }
        }
        // Return the count of subarrays with sum equal to k
        return count;

      
        // Optimal approach using a hashmap to store prefix sums
      
        unordered_map<int, int> prefixSumCount; // Map to store prefix sums and their counts
        prefixSumCount[0] = 1; // Initialize to handle the case where a subarray itself equals k
        int Sum = 0; // Initialize the running sum
        int count = 0; 
        // Iterate over each element in the nums array
        for (int i : nums) {
            Sum += i;
            
            // Check if there is a prefix sum that when removed leaves a sum of k
            if (prefixSumCount.find(Sum - k) != prefixSumCount.end()) {
                count += prefixSumCount[Sum - k]; // Increment count by the number of times the prefix sum has occurred
            }
            
            // Update the count of the current prefix sum in the hashmap
            prefixSumCount[Sum]++;
        }
        
        // Return the count of subarrays with sum equal to k found using the optimal approach
        return count;
    }
};
