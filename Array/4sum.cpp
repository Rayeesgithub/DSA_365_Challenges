https://leetcode.com/problems/4sum/
Example 1:
Input Format:arr[] = [1,0,-1,0,-2,2], target = 0
Result: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Explanation:We have to find unique quadruplets from the array such that the sum of those
elements is equal to the target sum given that is 0. The result obtained is such that the sum of the quadruplets yields 0.






  // Broute force solution
class Solution {
public:
 
// Brute force solution
// Time Complexity: O(n^4) due to 4 nested loops
// Space Complexity: O(1) excluding output vector

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;   // To store all unique quadruplets
        int n = nums.size();

        // -------------------------------
        // Try every combination of 4 numbers
        // -------------------------------
        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                for (int k = j + 1; k < n; k++) {

                    for (int m = k + 1; m < n; m++) {

                        // Calculate sum of 4 elements
                        long long sum = 1LL * nums[i] + nums[j] + nums[k] + nums[m];

                        // If sum matches target -> potential quadruplet
                        if (sum == target) {

                            // Create quadruplet
                            vector<int> temp = { nums[i], nums[j], nums[k], nums[m] };

                            // Sort to remove duplicate combinations
                            sort(temp.begin(), temp.end());

                            // Insert only if it doesn't already exist
                            if (find(ans.begin(), ans.end(), temp) == ans.end()) {
                                ans.push_back(temp);
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }
};






// Optimal approach using two pointers
       // Optimal approach using sorting + 2 pointers
// Time Complexity: O(n^3)
// Space Complexity: O(1) excluding result storage

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> ans;   // To store all quadruplets
        int n = nums.size();

        sort(nums.begin(), nums.end()); // Step 1: Sort array

        // ----------------------------------------------
        // Fix the first element (i)
        // ----------------------------------------------
        for (int i = 0; i < n; i++) {

            // Avoid duplicates for nums[i]
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // ----------------------------------------------
            // Fix the second element (j)
            // ----------------------------------------------
            for (int j = i + 1; j < n; j++) {

                // Avoid duplicates for nums[j]
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int k = j + 1;     // Third pointer
                int l = n - 1;     // Fourth pointer (moving from end)

                // Two-pointer approach for remaining two numbers
                while (k < l) {

                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    // If we found a valid quadruplet
                    if (sum == target) {

                        vector<int> temp = { nums[i], nums[j], nums[k], nums[l] };
                        ans.push_back(temp);

                        k++;
                        l--;

                        // Skip duplicates for nums[k]
                        while (k < l && nums[k] == nums[k - 1]) k++;

                        // Skip duplicates for nums[l]
                        while (k < l && nums[l] == nums[l + 1]) l--;
                    }

                    else if (sum < target) {
                        k++;    // Increase sum
                    }

                    else {
                        l--;    // Decrease sum
                    }
                }
            }
        }

        return ans;
    }
};
