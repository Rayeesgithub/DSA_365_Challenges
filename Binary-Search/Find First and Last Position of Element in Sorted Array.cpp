https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
//striver sheet

// broute force 
#include <vector>
using namespace std;
vector<int> searchRange(vector<int>& nums, int target) {
    // Initialize the result vector with -1, -1 (in case target is not found)
    vector<int> result(2, -1);    // or int ans1=-1; int ans2=-1;
  // Find the first occurrence of the target
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) {
            result[0] = i;
            break; // Once the first occurrence is found, break out of the loop
        }
    }
    // Find the last occurrence of the target
    for (int i = nums.size() - 1; i >= 0; i--) {
        if (nums[i] == target) {
            result[1] = i;
            break; // Once the last occurrence is found, break out of the loop
        }
    }
 return result; // Return the result vector
}


// optimal approach 
class Solution {
public:
    // Function to find the last occurrence of the target
    int findlastOccurence(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;
        int ans = -1; 
        
        // Binary search
        while (s <= e) {
            int mid = s + (e - s) / 2; // Calculate the middle index
            
            if (nums[mid] == target) {
                ans = mid; // Update the answer
                s = mid + 1; // Move the start index to mid + 1 to search the right half
            } else if (nums[mid] < target) {
                s = mid + 1; // Move the start index to mid + 1 to search the right half
            } else {
                e = mid - 1; // Move the end index to mid - 1 to search the left half
            }
        }
        return ans; // Return the last occurrence index
    }
    
    // Function to find the first occurrence of the target
    int findfirstOccurence(vector<int>& nums, int target) {
        int s = 0; // Start index
        int e = nums.size() - 1; // End index
        int ans = -1; // Variable to store the answer, initialized to -1
        
        // Binary search
        while (s <= e) {
            int mid = s + (e - s) / 2; // Calculate the middle index
            
            if (nums[mid] == target) {
                ans = mid; // Update the answer
                e = mid - 1; // Move the end index to mid - 1 to search the left half
            } else if (nums[mid] < target) {
                s = mid + 1; // Move the start index to mid + 1 to search the right half
            } else {
                e = mid - 1; // Move the end index to mid - 1 to search the left half
            }
        }
        return ans; // Return the first occurrence index
    }
    
    // Function to find the first and last occurrence of the target
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstOccurence = findfirstOccurence(nums, target); // Find the first occurrence
        int lastOccurence = findlastOccurence(nums, target); // Find the last occurrence
        
        return {firstOccurence, lastOccurence}; // Return the first and last occurrence indices
    }
};
