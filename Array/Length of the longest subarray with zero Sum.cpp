// Broute force
Example 1:  
Input: nums = [10, 5, 2, 7, 1, 9], k = 15  
Output: 4  
Explanation: The longest sub-array with a sum equal to 15 is [5, 2, 7, 1], which has a length of 4. This sub-array starts at index 1 and ends at index 4, 
and the sum of its elements (5 + 2 + 7 + 1) equals 15. Therefore, the length of this sub-array is 4.


 // approach1
 Time Complexity: O(n²) && Space Complexity: O(1)
 
int maxLength(vector<int>& arr) {

    int maxi = 0;          // Store maximum length of subarray with sum = 0
    int n = arr.size();

    // Outer loop picks starting index i
    for(int i = 0; i < n; i++) {

        int sum = 0;       // Reset sum for new starting index i

        // Inner loop picks ending index j
        for(int j = i; j < n; j++) {

            sum += arr[j]; // Add elements from i to j

            // If the sum from i to j is zero → we found a subarray
            if(sum == 0) {

                int len = (j - i + 1);  // Calculate length of this subarray

                // Update maximum length
                maxi = max(maxi, len);
            }
        }
    }

    return maxi;
}


//optimal
Time Complexity: O(n) && Space Complexity: O(n)

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int longestSubarrayWithZeroSum(vector<int>& arr) {
    unordered_map<int, int> mp;   // prefixSum -> first index
    int prefixSum = 0;
    int maxLen = 0;
    
    for(int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i];
        
        // Case 1: Subarray from start to i has sum 0
        if(prefixSum == 0) {
            maxLen = i + 1;
        }
        
        // Case 2: Same prefixSum seen before
        if(mp.find(prefixSum) != mp.end()) {
            int prevIndex = mp[prefixSum]; //This line is fetching the index where we previously saw the same prefix sum.
            maxLen = max(maxLen, i - prevIndex);
        }
        else {
            // Store only the first occurrence
            mp[prefixSum] = i;
        }
    }
    return maxLen;
}

// Driver Code
int main() {
    vector<int> arr = {9, -3, 3, -1, 6, -5};
    cout << "Longest Subarray Length with Sum 0: " 
         << longestSubarrayWithZeroSum(arr) << endl;
    return 0;
}

