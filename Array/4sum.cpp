https://leetcode.com/problems/4sum/
//striver
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size(); // Size of the input vector

        // Brute force approach using sets to store unique quadruplets
        set<vector<int>> st; // Set to store unique quadruplets
        
        // Iterate over all possible quadruplets
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    for (int l = k + 1; l < n; l++) {
                        // Check if the quadruplet sums to the target
                        if (nums[i] + nums[j] + nums[k] + nums[l] == target) {
                            vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                            // Sort the quadruplet to ensure uniqueness
                            sort(temp.begin(), temp.end());
                            // Insert the quadruplet into the set
                            st.insert(temp);
                        }
                    }
                }
            }
        }

        // Better approach using hashset to avoid duplicates
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                set<long long> hashset; // Hashset to store elements
                for (int k = j + 1; k < n; k++) {
                    // Calculate the sum of three elements
                    long long sum = nums[i] + nums[j] + nums[k];
                    long long fourth = target - sum; // Find the fourth element needed
                    // Check if the fourth element is in the hashset
                    if (hashset.find(fourth) != hashset.end()) {
                        vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth};
                        // Sort the quadruplet to ensure uniqueness
                        sort(temp.begin(), temp.end());
                        // Insert the quadruplet into the set
                        st.insert(temp);
                    }
                    // Insert the current element into the hashset
                    hashset.insert(nums[k]);
                }
            }
        }

        // Convert the set to a vector of vectors
        vector<vector<int>> ans(st.begin(), st.end());

        // Optimal approach using two pointers
        sort(nums.begin(), nums.end()); // Sort the input vector
        
        // Iterate over the array
        for (int i = 0; i < n; i++) {
            // Avoid duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            for (int j = i + 1; j < n; j++) {
                // Avoid duplicates for the second element
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                
                int k = j + 1; // Third pointer
                int l = n - 1; // Fourth pointer
                
                while (k < l) {
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    
                    if (sum == target) {
                        // Found a valid quadruplet
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;

                        // Skip duplicates for the third and fourth elements
                        while (k < l && nums[k] == nums[k - 1]) k++;
                        while (k < l && nums[l] == nums[l + 1]) l--;
                    } else if (sum < target) {
                        k++; // Increase the third pointer
                    } else {
                        l--; // Decrease the fourth pointer
                    }
                }
            }
        }

        return ans; // Return the result
    }
};
