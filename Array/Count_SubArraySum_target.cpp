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
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySumCount(vector<int>& arr, int k) {
    int n = arr.size();
    unordered_map<int, int> pref_map; // Stores {prefix_sum -> how_many_times_seen}
    
    // Base Case: A prefix sum of 0 has occurred exactly 1 time 
    // (handles subarrays starting from index 0)
    pref_map[0] = 1;
    
    int prefix_sum = 0;
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        prefix_sum += arr[i]; // Update cumulative sum
        
        int remove = prefix_sum - k; // Find the complement we need to discard
        
        // If that complement exists, add its frequency to our total count
        if (pref_map.find(remove) != pref_map.end()) {
            count += pref_map[remove];
        }
        
        // Record the current prefix sum into the map
        pref_map[prefix_sum]++;
    }
    
    return count;
}

