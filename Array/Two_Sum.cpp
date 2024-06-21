//https://leetcode.com/problems/two-sum/
//striver sheet
class Solution {
public:
     // approach1-broute force Time Complexity: O(N2), Space Complexity: O(1)
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();vector<int>ans;
    //    for(int i=0; i<n; i++){
    //     long long int sum=0; 
    //     for(int j=i+1; j<n; j++){
           
    //         if( nums[i]+nums[j]==target){
    //             ans={i,j};
    //         }
    //     }
    //    } 
    //    return ans;

      //approach2
    int left=0; int right=n-1;
   
    vector<pair<int,int>>pr;
     for (int i = 0; i < n; ++i) {
        pr.push_back({nums[i], i});
    }

     sort(nums.begin(),nums.end());
    while(left<right){
          int sum = pr[left].first+pr[right].first;
        if(sum>target){
            right--;
        }
        else if(sum<target){
            left++;
        }
        else{
          return {pr[left].second, pr[right].second};
        }
    }
    return {-1,-1};
    }

    //3rd approach
    //    unordered_map<int, int> numMap;
    //     int n = nums.size();

    //     for (int i = 0; i < n; i++) {
    //         int complement = target - nums[i];
    //         if (numMap.count(complement)) {
    //             return {numMap[complement], i};
    //         }
    //         numMap[nums[i]] = i;
    //     }

    //     return {}; // No solution found
    // 
    //}
};
