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
     

// 3 pointers:
// low   → position where next 0 should go
// mid  → current pointer scanning the array
// end → position where next 2 should go

// Loop until md crosses end
#include <vector>
#include <algorithm>
using namespace std;

void sort012Template(vector<int>& arr) {
    int n = arr.size();
    
    // 1. Initialize the 3 pointers
    int low = 0;
    int mid = 0;
    int high = n - 1;
    
    // 2. Loop until mid crosses high
    while (mid <= high) {
        
        // 3. Core Logic depending on current element
        if (arr[mid] == 0) {
            // Put it in the '0' zone by swapping with low
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        } 
        else if (arr[mid] == 1) {
            // It is already in the right place ('1' zone), just move mid forward
            mid++;
        } 
        else { // arr[mid] == 2
            // Put it in the '2' zone by swapping with high
            swap(arr[mid], arr[high]);
            high--;
            // Notice we do NOT increment mid here! 
            // The newly swapped element at mid needs to be evaluated in the next loop.
        }
    }
}

⏱️ Complexity
Time: O(n) (single pass)
Space: O(1)
