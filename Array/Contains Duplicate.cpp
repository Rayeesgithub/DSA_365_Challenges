https://leetcode.com/problems/contains-duplicate/description/

Example 1:
Input: nums = [1,2,3,1]
Output: true

Explanation:
The element 1 occurs at the indices 0 and 3.

  
  // appraoch 1-> Broute force
   bool containsDuplicate(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i]==nums[j]){
                    return true;
                }
            }
        }
   return false;
    }



// Appraoch 2-> better approach
// Complexity-> O(n log n).

bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1])
                return true;
        }
        return false;
    }




// approach 3 -> better approach
// time complexity of O(n)
 bool containsDuplicate(vector<int>& nums) {
  unordered_map<int,int>mpp;

  for(int i=0; i<n; i++){
    mpp[nums[i]]++;
  }

  for(auto it:mpp){
   if(it.second>1){
    return true;
   }
  }
  return false;


// other approach 1
 bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> seen;
        for (auto it : nums) {
           if (seen.count(it) >= 1)
                return true;
            seen[it]++;
        }
        return false;
    }

};

// other approach 2

#include <vector>
#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> seen;
        
        for (int num : nums) {
            // If the number is already in the set, we found a duplicate
            if (seen.find(num) != seen.end()) {
                return true;
            }
            // Otherwise, add the number to the set
            seen.insert(num);
        }
        
        // No duplicates found after checking the entire array
        return false;
    }
};
