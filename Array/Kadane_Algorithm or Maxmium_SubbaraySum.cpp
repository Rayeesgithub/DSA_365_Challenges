//https://leetcode.com/problems/maximum-subarray/description/

Example 1:  
Input: nums = [2, 3, 5, -2, 7, -4]  
Output: 15  
Explanation: The subarray from index 0 to index 4 has the largest sum = 15, which is the maximum sum of any contiguous subarray.



   // Approach 1: Brute Force (Time: O(n^3), Space: O(1))

int maxSubArray(vector<int>& nums) {

    int maxi = INT_MIN;          // stores maximum subarray sum
    int n = nums.size();

    // pick starting index i
    for (int i = 0; i < n; i++) {

        // pick ending index j
        for (int j = i; j < n; j++) {

            int sum = 0;         // reset sum for subarray (i → j)

            // compute sum of nums[k] from k = i to k = j
            for (int k = i; k <= j; k++) {
                sum = sum + nums[k];
            }

            // update maximum sum found so far
            maxi = max(maxi, sum);
        }
    }

    // return the maximum subarray sum
    return maxi;

        

        
      // Approach 2: Better Approach (still O(n^2))
        // Approach 2: Better Approach (Time: O(n^2), Space: O(1))

int maxSubArray(vector<int>& nums) {

    int maxi = INT_MIN;          // stores maximum subarray sum
    int n = nums.size();

    // pick starting index i
    for (int i = 0; i < n; i++) {

        int sum = 0;             // reset sum for new start index

        // expand subarray from i to j
        for (int j = i; j < n; j++) {

            sum = sum + nums[j]; // add current element into running sum

            // update maximum sum for each j
            maxi = max(maxi, sum);
        }
    }

    // return the maximum subarray sum
    return maxi;
}

        


        
      // Approach 3: Optimal Approach (Kadane's Algorithm)
       Time=(N) 
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
