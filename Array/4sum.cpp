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

#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<int>> result;
    
    // 1. Sort the array to handle duplicates and enable two-pointers
    sort(nums.begin(), nums.end());
    
    // 2. Fix the first element 'i' (Stops at n-3)
    for (int i = 0; i < n - 3; i++) {
        // Skip duplicates for the first element
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        
        // 3. Fix the second element 'j' (Starts after i, stops at n-2)
        for (int j = i + 1; j < n - 2; j++) {
            // Skip duplicates for the second element
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            
            // 4. Two Pointers initialization for the remaining two slots
            int left = j + 1;
            int right = n - 1;
            
            while (left < right) {
                // Use long long to prevent integer overflow when adding 4 numbers
                long long current_sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                
                if (current_sum == target) {
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});
                    
                    // Skip duplicates for left and right pointers
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    
                    left++;
                    right--;
                } 
                else if (current_sum < target) {
                    left++; // Need a larger sum
                } 
                else {
                    right--; // Need a smaller sum
                }
            }
        }
    }
    return result;
}
    }
};
