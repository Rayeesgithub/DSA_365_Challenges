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
        // Pattern two-pointer technique
     #include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> result;
    
    // 1. Sort the array to enable the two-pointer technique and easily skip duplicates
    sort(nums.begin(), nums.end());
    
    // 2. Fix the first element 'i'
    for (int i = 0; i < n - 2; i++) {
        // Skip duplicate values for the first element
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        
        // Optimization: If the lowest possible sum is > 0, no triplets can sum to 0
        if (nums[i] + nums[i + 1] + nums[i + 2] > 0) break;
        
        // 3. Initialize Two Pointers for the remaining array segment
        int left = i + 1;
        int right = n - 1;
        
        while (left < right) {
            int current_sum = nums[i] + nums[left] + nums[right];
            
            if (current_sum == 0) {
                result.push_back({nums[i], nums[left], nums[right]});
                
                // Move pointers past duplicate values to ensure unique triplets
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;
                
                left++;
                right--;
            } 
            else if (current_sum < 0) {
                left++; // Sum is too small, move left pointer to get a larger value
            } 
            else {
                right--; // Sum is too large, move right pointer to get a smaller value
            }
        }
    }
    return result;
}
