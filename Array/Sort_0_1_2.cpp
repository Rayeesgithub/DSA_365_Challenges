//https://leetcode.com/problems/sort-colors/
// striver sheet
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Approach 1: Using sorting (commented out)
        // This approach is straightforward but doesn't take advantage of the problem constraints.
        // sort(nums.begin(), nums.end());
      

        // Approach 2: Counting occurrences of each color    Time Complexity: O(N),Space Complexity: O(1) 
      
        int count0 = 0, count1 = 0, count2 = 0;

        // First pass: Count the number of 0's, 1's, and 2's
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) count0++;
            else if (nums[i] == 1) count1++;
            else if (nums[i] == 2) count2++;
        }

        // Second pass: Overwrite the array with the correct number of 0's, 1's, and 2's
        for (int i = 0; i < count0; i++) nums[i] = 0;
        for (int i = count0; i < count0 + count1; i++) nums[i] = 1;
        for (int i = count0 + count1; i < nums.size(); i++) nums[i] = 2;

      
        // Approach 3: Dutch National Flag Algorithm (Optimal solution)  Time Complexity: O(N),Space Complexity: O(1) 
        int s = 0, md = 0, end = nums.size() - 1;

        // Three-way partitioning to sort the array in one pass
        while (md <= end) {
            if (nums[md] == 0) {
                // Swap the current element with the start position
                swap(nums[s], nums[md]);
                s++;
                md++;
            } else if (nums[md] == 1) {
                // If the element is 1, just move the mid pointer
                md++;
            } else if (nums[md] == 2) {
                // Swap the current element with the end position
                swap(nums[md], nums[end]);
                end--;
            }
        }
    }
};
