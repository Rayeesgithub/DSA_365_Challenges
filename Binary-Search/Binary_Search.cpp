https://leetcode.com/problems/binary-search/submissions/1311355898/
// striver sheets
class Solution {
public:
    int search(vector<int>& nums, int target) {
      
        // Brute force approach (commented out)
        Iterate through each element in the array
        for (int i = 0; i < nums.size(); i++) {
            // If the target is found, return its index
            if (nums[i] == target) {
                return i;
            }
        }
        // If the target is not found, return -1
        return -1;

      
        // Optimal approach using binary search
      
        int start = 0; // Initialize start pointer
        int end = nums.size() - 1; // Initialize end pointer

        // Binary search loop
        while (start <= end) {
            int mid = start + (end - start) / 2; // Calculate the mid-point to avoid overflow
            if (nums[mid] == target) { // If the mid element is the target, return its index
                return mid;
            } else if (nums[mid] < target) { // If the mid element is less than the target
                start = mid + 1; // Move the start pointer to the right half
            } else { // If the mid element is greater than the target
                end = mid - 1; // Move the end pointer to the left half
            }
        }
        return -1; // If the target is not found, return -1
    }
};
