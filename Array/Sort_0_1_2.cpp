//https://leetcode.com/problems/sort-colors/


Input: nums = [1, 0, 2, 1, 0]
Output: [0, 0, 1, 1, 2]
Explanation: The nums array in sorted order has 2 zeroes, 2 ones and 1 two



class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Approach 1: Using sorting (commented out)
        // This approach is straightforward but doesn't take advantage of the problem constraints.
        // sort(nums.begin(), nums.end());
      


        
        // Approach 2: Counting occurrences of each color    Time Complexity: O(N),Space Complexity: O(1) 
      
      void sortZeroOneTwo(vector<int>& nums) {
        // Initialize count variables for 0s, 1s, and 2s
        int count0 = 0, count1 = 0, count2 = 0;

        // Count the frequency of 0s, 1s, and 2s in the array
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) count0++;
            else if(nums[i] == 1) count1++;
            else count2++;
        }

        // Overwrite the array with the counted values
        int index = 0;

        // Fill with 0s
        while(count0--) {
            nums[index++] = 0;
        }

        // Fill with 1s
        while(count1--) {
            nums[index++] = 1;
        }

        // Fill with 2s
        while(count2--) {
            nums[index++] = 2;
        }




          
        // Approach 3: Dutch National Flag Algorithm (Optimal solution)  Time Complexity: O(N),Space Complexity: O(1) 
      int s = 0, md = 0, end = nums.size() - 1;

// 3 pointers:
// s   → position where next 0 should go
// md  → current pointer scanning the array
// end → position where next 2 should go

// Loop until md crosses end
while (md <= end) {

    // CASE 1 → Current element is 0
    if (nums[md] == 0) {

        // Swap current element with the element at 's'
        swap(nums[s], nums[md]);

        s++;       // move zero-section forward
        md++;      // move mid forward (processed)
    } 

    // CASE 2 → Current element is 1
    else if (nums[md] == 1) {

        // 1 is already in correct middle zone → just skip
        md++;      // just move forward
    } 

    // CASE 3 → Current element is 2
    else if (nums[md] == 2) {

        // swap current element with 'end' index
        swap(nums[md], nums[end]);

        end--;     // shrink 2's section from the back

        // NOTE: do NOT md++ here
        // Because swapped element from 'end' could be 0,1, or 2.
        // We must re-check nums[md] again.
    }
}

};
