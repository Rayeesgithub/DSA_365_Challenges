//https://leetcode.com/problems/majority-element/
//striver sheet

Example 1:  
Input: nums = [7, 0, 0, 1, 7, 7, 2, 7, 7]  
Output: 7  
Explanation: The number 7 appears 5 times in the 9-sized array, making it the most frequent element.


   // Approach 1: Brute force  Time=0(n^2) && space=0(1) 
int majorityElement(vector<int>& nums) {
    int ans;
    
    // Loop over each element as the candidate
    for (int i = 0; i < nums.size(); i++) {
        int count = 0;  // Reset count for every new candidate
        
        // Count frequency of nums[i]
        for (int j = 0; j < nums.size(); j++) {
            if (nums[i] == nums[j]) 
                count++;    // Increase count when match found
        }

        // If its count is greater than n/2, it is majority element
        if (count > nums.size() / 2) {
            ans = nums[i];
            break;    // We found answer, break early
        }
    }

    return ans;  // Return result of brute-force approach


      
       
    // Approach 2: 
⏱️ Complexity
Time → O(n)
Space → O(n))
      
          int mid = nums.size() / 2; 
    unordered_map<int, int> mp;   // Stores element → frequency
    
    // Count frequency of each number
    for (int i = 0; i < nums.size(); i++) {
        mp[nums[i]]++;    // Increase count in map
    }

    // Iterate map to find element with count > n/2
    for (auto it : mp) {
        if (it.second > mid) {   // it.second = frequency
            ans = it.first;      // it.first = element
        }
    }

    return ans;


      
    
             
             
             
             
             
             // Approach 3:
      // PATTERN-> Moore’s Voting Algorithm
        Time = O(n), Space = O(1))
            
          // Size of the array
   
           
#include <vector>
using namespace std;

int majorityElementN2(vector<int>& nums) {
    int n = nums.size();
    int candidate = 0;
    int count = 0;
    
    // --- PHASE 1: The Voting Process ---
    for (int i = 0; i < n; i++) {
        // If count drops to 0, choose the current element as the new candidate
        if (count == 0) {
            candidate = nums[i];
            count = 1;
        }
        // If current element matches the candidate, increment count
        else if (nums[i] == candidate) {
            count++;
        }
        // If it's a different element, decrement count (Cancellation)
        else {
            count--;
        }
    }
    
    // --- PHASE 2: Verification Process ---
    // Note: If the problem statement GUARANTEES that a majority element 
    // always exists, you can skip Phase 2 entirely and just return 'candidate'.
    int actual_count = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == candidate) {
            actual_count++;
        }
    }
    
    if (actual_count > n / 2) {
        return candidate;
    }
    
    return -1; // Return -1 if no majority element exists
}
