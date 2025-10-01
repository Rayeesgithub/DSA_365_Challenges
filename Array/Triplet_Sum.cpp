//https://leetcode.com/problems/3sum/
// striver sheet
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size(); // Size of the input vector
        set<vector<int>> st; // Set to store unique triplets

        // Brute force approach
        // Iterate over all possible triplets
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    // Check if the triplet sums to zero
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        // Sort the triplet to ensure uniqueness
                        sort(temp.begin(), temp.end());
                        // Insert the triplet into the set
                        st.insert(temp);
                    }
                }
            }
            vector<vector<int>> ans(st.begin(), st.end());
    return ans;
        }




class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        vector<int>triplet={nums[i],nums[j],nums[k]};
                        sort(triplet.begin(),triplet.end());
                        if(find(ans.begin(),ans.end(),triplet)==ans.end()){
                            ans.push_back(triplet);
                        }
                    }
                }
            }
        }
        return ans;
    }
};


        

        // Better approach
        // Using a hashset to store seen elements
        for(int i = 0; i < n; i++) {
            set<int> hashset;
            for(int j = i + 1; j < n; j++) {
                int third = -(nums[i] + nums[j]);
                // Check if the third element exists in the hashset
                if(hashset.find(third) != hashset.end()) {
                    vector<int> temp = {nums[i], nums[j], third};
                    // Sort the triplet to ensure uniqueness
                    sort(temp.begin(), temp.end());
                    // Insert the triplet into the set
                    st.insert(temp);
                }
                // Insert the current element into the hashset
                hashset.insert(nums[j]);
            }
        }

        // Optimal approach
        // Sort the array first to use two-pointer technique
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans; // Vector to store the final result

        for (int i = 0; i < n; i++) {
            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1; // Second pointer
            int k = n - 1; // Third pointer

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum > 0) {
                    // If the sum is greater than zero, move the third pointer left
                    k--;
                } else if (sum < 0) {
                    // If the sum is less than zero, move the second pointer right
                    j++;
                } else {
                    // If the sum is zero, we've found a valid triplet
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    // Skip duplicates for the second and third elements
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }
        // // Convert the set of vectors to a vector of vectors
        // vector<vector<int>> ans(st.begin(), st.end());
        return ans; // Return the final list of unique triplets
    }
};
