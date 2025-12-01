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


      
       
    // Approach 2: (Time = O(n), Space = O(n))
      
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


      
        // Approach 3: Moore’s Voting Algorithm
        Time = O(n), Space = O(1))
            
          // Size of the array
    int n = nums.size();
    int cnt = 0;   // Counter for candidate
    int el;        // Candidate element

    // Step 1: Find a candidate
    for (int i = 0; i < n; i++) {

        if (cnt == 0) {      // When no candidate, choose new one
            el = nums[i];
            cnt = 1;
        } 
        else if (nums[i] == el) {
            cnt++;           // If same, increase strength
        }
        else {
            cnt--;           // If different, decrease strength
        }
    }

    // Step 2: Verify candidate (optional but safe)
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == el) 
            cnt1++;          // Count candidate occurrences
    }

    // Check if candidate is actually majority
    if (cnt1 > n / 2) return el;

    return -1;               // Not expected by constraints
}
