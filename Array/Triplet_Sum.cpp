//https://leetcode.com/problems/3sum/
Example 1: 
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: Out of all possible unique triplets possible, [-1,-1,2] and [-1,0,1] satisfy the condition of summing up to zero with i!=j!=k







    
// approach1 Time Complexity: O(N^3) space=0(n)
// Function to find all unique triplets whose sum = 0
vector<vector<int>> threeSum(vector<int>& nums) {

    int n = nums.size(); 
    set<vector<int>> st;   // Set is used to avoid duplicate triplets

    // -------------------------------------------
    // Try all possible triplets using 3 nested loops
    // -------------------------------------------
    for (int i = 0; i < n; i++) {

        for (int j = i + 1; j < n; j++) {

            for (int k = j + 1; k < n; k++) {

                // Check if the triplet sums to zero
                if (nums[i] + nums[j] + nums[k] == 0) {

                    // Store the triplet in a temporary vector
                    vector<int> temp = {nums[i], nums[j], nums[k]};

                    // Sorting ensures that {1,-1,0} and {0,1,-1} become same
                    sort(temp.begin(), temp.end());

                    // Insert sorted triplet (removes duplicates automatically)
                    st.insert(temp);
                }
            }
        }
    }

    // Convert set → vector for final answer
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

int main() {

    vector<int> arr = {-1,0,1,2,-1,-4};

    // Function call
    vector<vector<int>> ans = threeSum(arr);

    // -----------------------------------------
    // Printing 2D vector (vector of triplets)
    // -----------------------------------------
    cout << "Triplets with sum = 0:\n";
    for (auto triplet : ans) {
        for (auto x : triplet) {
            cout << x << " ";
        }
        cout << endl;
    }
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
                        // nahi mila
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
   What it does
find(ans.begin(), ans.end(), triplet) → searches in the ans vector (which stores triplets we already found) for the current triplet.
If it doesn’t find the triplet, then find() will return ans.end().
So == ans.end() means “triplet is not already in ans”.
If triplet is new, we push it into ans using ans.push_back(triplet).


        


        // Optimal approach  Time Complexity: O(NlogN)+O(N2), space=(1)
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
