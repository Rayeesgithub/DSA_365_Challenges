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

int maxLength(vector<int>& arr) {

    int maxi = 0;                     // Stores longest zero-sum subarray
    unordered_map<int, int> mp;       // Stores first index where a prefix sum appears
    int sum = 0;                      // Running prefix sum

    for(int i = 0; i < arr.size(); i++) {

        sum += arr[i];                // Update prefix sum

        // CASE 1: Entire subarray from 0 to i has sum = 0
        if(sum == 0) {
            maxi = i + 1;
        }

        // CASE 2: Prefix sum seen before
        // Means subarray (previousIndex+1 to i) has sum = 0
        else if(mp.find(sum) != mp.end()) {

            int len = i - mp[sum];    // Length of zero-sum subarray
            maxi = max(maxi, len);    // Update max length
        }

        // CASE 3: First time this prefix sum occurs → store index
        else {
            mp[sum] = i;
        }
    }

    return maxi;
}
