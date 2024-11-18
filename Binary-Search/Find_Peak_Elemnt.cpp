https://leetcode.com/problems/find-peak-element/
// striver sheet
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



//approach2 ->broute force
int findPeak(vector<int>&arr,int n){
   int index=0;
   if(arr[n-1]<arr[n]){
    return n-1;
   }
   if(arr[0]>arr[1]){
    return 0;
   }
   for(int i=0; i<n-1; i++){
    if(arr[i]<arr[i+1]){
        index=i;
    }
    else{
        break;
    }
   }
   return (index)+1;
}



// optimal Approach->this approach may fail interm some cases
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // Start from the second element (index 1) and go up to the second last element (index n-2)
        int s = 1; 
        int e = nums.size() - 2;
        int n = nums.size();
        
        // Edge case: if there's only one element, it's the peak
        if (n == 1) return 0;
        
        // Edge case: if the first element is greater than the second, it's a peak
        if (nums[0] > nums[1]) return 0;
        
        // Edge case: if the last element is greater than the second last, it's a peak
        if (nums[n - 1] > nums[n - 2]) return n - 1;
        
        // Perform binary search between the second and second last elements
        while (s <= e) {
            int mid = s + (e - s) / 2; // Calculate mid to avoid overflow
            
            // If nums[mid] is greater than its neighbors, it's a peak
            if (nums[mid - 1] <= nums[mid] && nums[mid] > nums[mid + 1]) {
                return mid;
            }
            
            // If we are in the left part of the peak
            if (nums[mid - 1] < nums[mid]) {
                s = mid + 1; // Move to the right part
            } else {
                e = mid - 1; // Move to the left part
            }
        }
        
        // Default return statement, ideally never reached
        return 0;
    }
};
