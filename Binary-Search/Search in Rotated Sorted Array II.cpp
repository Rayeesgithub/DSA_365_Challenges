https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
// striver

// Broute force
 bool search(vector<int>& nums, int target) {
        bool ans=false;
        for(int i=0; i<nums.size(); i++){
         if(nums[i]==target){
            ans=true;
         }
        }
        return ans;
    }


// optimal Approach
bool search(vector<int>& nums, int target) {
        int s=0; int e=nums.size()-1; bool ans=false;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target){
            ans=true;
            }
          
          // edge case
          // Check for an edge case where the start, mid, and end elements are all equal
if (nums[s] == nums[mid] && nums[mid] == nums[e]) {
    // Increment start index to skip duplicate element
    s = s + 1;
// Decrement end index to skip duplicate element
    e = e - 1;
  continue;// Continue to the next iteration of the loop
}
          
          // left part may sorted 
            if(nums[s]<=nums[mid]){
                // target found may in left part
                if(nums[s]<=target && target<nums[mid]){
                    e=mid-1;
                }
                else{
                    s=mid+1;
                }
            }
            else{
                if(nums[s]>target && nums[mid]<=target){
                    s=mid+1;
                }
                else{
                    e=mid-1;
                }
            }
        }
        return ans;
    }
};
