//https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
// striver 
//optimal approach-> Time Complexity: O(N)  && Space Complexity: O(1)
 bool check(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        for(int i=1; i<n; i++){
         if(nums[i-1]>nums[i]) count++;
        }
        if(nums[n-1]>nums[0]) count++;
        return count==1 ? true : false;
    }



//approach2
bool check(vector<int>& nums) {
    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] > nums[(i + 1) % n]) {
            count++;
        }
        // More than one break point means the array can't be sorted by a single rotation
        if (count > 1) {
            return false;
        }
    }
    return true;



