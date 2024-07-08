https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
// striver sheet

// broute Force
 int findMin(vector<int>& nums) {
        // broute force
        int mini=INT_MAX;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<mini){
                mini=nums[i];
            }
        }
        return mini;
    }

// optimal approach
int findMin(vector<int>& nums) {
    int ans = INT_MAX;
    int s = 0; // Start index of the array
    int e = nums.size() - 1; // End index of the array

    while (s <= e) {
        int mid = s + (e - s) / 2; 
        
        // If the subarray from s to e is sorted
        if (nums[s] <= nums[e]) {
            // The minimum element in this sorted subarray is nums[s]
            ans = min(ans, nums[s]);
            break; // No need to search further as we found the minimum in this subarray
        }
        
        // If the left part is sorted
        if (nums[s] <= nums[mid]) {
            // Update ans with the minimum value found so far
            ans = min(ans, nums[s]);
            s = mid + 1; // Move the start index to mid + 1 to search in the right part
        } 
        // If the right part is sorted
        else {
            // Update ans with the minimum value found so far
            ans = min(ans, nums[mid]);
            e = mid - 1; // Move the end index to mid - 1 to search in the left part
        }
    }
    return ans; // Return the minimum element found
}
