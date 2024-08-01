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





// broute force 
bool isSorted(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[i])
        return false;
    }
  }

  return true;
}
