

//
// Broute Force
int findPeakElement(vector<int>& nums) {
        // broute force 
        int index=-1; int maxi=INT_MIN;
        for(int i=0; i<nums.size(); i++){
            if(maxi<nums[i]){
                maxi=nums[i];
                index=i;
            }
        }
        if(maxi==INT_MIN){
            return 0;
        }
        return index;
    }

// optimal Approach
explain this code using comment line->class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s=1; 
        int e=nums.size()-2;
        int n=nums.size();
        if(n==1) return 0;
        if(nums[0]>nums[1]) return 0;
         if (nums[n - 1] > nums[n - 2]) return n - 1;
        while(s<=e){
            int mid=s+(e-s)/2; 
       
          //If arr[mid] is the peak:
            if( nums[mid-1]<=nums[mid] && nums[mid]>nums[mid+1]){
               return mid;
            }
            // If we are in the left:
            if(nums[mid-1]<nums[mid]){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        
        return 0;
    }
};
