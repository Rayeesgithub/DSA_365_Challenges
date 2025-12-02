//https://leetcode.com/problems/subarray-sum-equals-k/description/
//striversheet

Input : N = 4, array[] = {3, 1, 2, 4}, k = 6
Output: 2
Explanation: The subarrays that sum up to 6 are [3, 1, 2] and [2, 4].

Input: N = 3, array[] = {1,2,3}, k = 3
Output: 2
Explanation: The subarrays that sum up to 3 are [1, 2], and [3]



    // Approach 1: Brute Force (Three loops)  Time: O(n³) && Space: O(1)
int subarraySum(vector<int>& arr, int k) {

    int n = arr.size(); // Size of the array
    int count = 0;      // Count of valid subarrays

    // Choose every possible starting index
    for (int i = 0; i < n; i++) {

        // Choose every possible ending index from i
        for (int j = i; j < n; j++) {

            int sum = 0; // Sum of current subarray

            // Compute sum of elements from index i to j
            for (int m = i; m <= j; m++) {
                sum += arr[m];
            }

            // Check if this subarray's sum equals k
            if (sum == k) {
                count++;
            }
        }
    }

    // Final count of subarrays whose sum = k
    return count;
}



// Approach 2: Better (Two loops)     Time: O(n^2) && Space: O(1)
// We avoid recalculating the subarray sum every time
int subarraySum(vector<int>& nums, int k) {

    int count = 0;

    // Pick starting index
    for (int i = 0; i < nums.size(); i++) {

        int sum = 0; // Reset sum for new start index

        // Expand the subarray from i to j
        for (int j = i; j < nums.size(); j++) {

            sum += nums[j]; // Add current element

            // If sum equals k, this is a valid subarray
            if (sum == k) {
                count++;
            }
        }
    }

    // Return how many subarrays have sum = k
    return count;
}




// Approach 3: Optimal using Prefix Sum + Hashmap Time: O(n) && Space: O(n)
int subarraySum(vector<int>& nums, int k) {

    unordered_map<int, int> prefixSumCount;  
    prefixSumCount[0] = 1;
    // This means: prefix sum = 0 has occurred once.
    // Helps when subarray starts from index 0.

    int Sum = 0;   // Running prefix sum
    int count = 0; // Count of valid subarrays

    // Iterate through all numbers in array
    for (int num : nums) {

        Sum += num; // Update prefix sum

        // Check if there exists a prefix such that:
        //    Sum - prefix = k 
        // => prefix = Sum - k
        if (prefixSumCount.find(Sum - k) != prefixSumCount.end()) {

            // Add the number of times (Sum - k) prefix appeared
            count += prefixSumCount[Sum - k];
        }

        // Store the current prefix sum frequency
        prefixSumCount[Sum]++;
    }

    // Final answer
    return count;
}
