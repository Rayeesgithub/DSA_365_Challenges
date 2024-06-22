//https://leetcode.com/problems/rearrange-array-elements-by-sign/
//striver sheet

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        broute force Time-com=0(N) && space-com=0(N)
     vector<int>ans,positive,negative;
     // Separate positive and negative elements
     for(int i=0; i<nums.size(); i++){
        if(nums[i]>=0)
        positive.push_back(nums[i]);
        else if(nums[i]<0){
            negative.push_back(nums[i]);
        }
     }   // Arrange positive and negative elements alternately
    int pos = 0, neg = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i % 2 == 0) {
            ans.push_back(positive[pos++]);
        } else {
            ans.push_back(negative[neg++]);
        }
      
    }

      
    //optimized
     vector<int> rearrangeArray(vector<int>& nums) {
    vector<int> ans(nums.size(), 0); // Create a result vector of the same size as nums, initialized to 0
    int pos = 0;  // Index for placing positive numbers
    int neg = 1;  // Index for placing negative numbers
    
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] > 0) { // If the current element is positive
            ans[pos] = nums[i]; // Place it at the current 'pos' index in the result array
            pos += 2; // Increment the pos index by 2 
        } else {     // If the current element is negative
            ans[neg] = nums[i]; // Place it at the current 'neg' index in the result array
            neg += 2; 
        }
    }
    return ans; 
}

};
