https://leetcode.com/problems/search-in-rotated-sorted-array/description/
// striver sheet

// broute force
 int search(vector<int>& nums, int target) {
         int ans=-1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==target){
             ans=i;
            }
        }
            return ans;

//optimal approach
class Solution {
public:
    // Function to search for the target value in a rotated sorted array
    int search(vector<int>& nums, int target) {
        int s = 0; // Start index
        int e = nums.size() - 1; // End index

        // Binary search loop
        while (s <= e) {
            int mid = s + (e - s) / 2; // Calculate mid index to prevent overflow

            // If the element at mid is equal to target, return mid index
            if (nums[mid] == target) {
                return mid;
            }

            // Check if the left half is sorted
            if (nums[s] <= nums[mid]) {
                // If target is in the left half, move the end to mid-1
                if (nums[s] <= target && nums[mid] > target) {
                    e = mid - 1;
                } else {
                    // Otherwise, move the start to mid+1
                    s = mid + 1;
                }
            } else {
                // If the right half is sorted
                // If target is in the right half, move the start to mid+1
                if (nums[s] > target && nums[mid] <= target) {
                    s = mid + 1;
                } else {
                    // Otherwise, move the end to mid-1
                    e = mid - 1;
                }
            }
        }

        // If target is not found, return -1
        return -1;
    }
};
