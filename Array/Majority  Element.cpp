class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Approach 1: Brute force
      
        int ans;
        
      // Iterate over each element to count its occurrences
        for (int i = 0; i < nums.size(); i++) {
           int  count = 0; // Reset count for each element
            for (int j = 0; j < nums.size(); j++) {
                if (nums[i] == nums[j]) count++; // Count occurrences
            }
            if (count > nums.size() / 2) { // Check if it is the majority element
                ans = nums[i];
                break; // Exit early if the majority element is found
            }
        }
        
        // Return the majority element found by the brute force method
        return ans;

      
        // Approach 2: Using a map to count occurrences
      
        int mid = nums.size() / 2; // Calculate half the size of the array
        unordered_map<int, int> mp; // Create a map to store element counts
        
        // Count occurrences of each element
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        // Find the majority element by checking counts in the map
        for (auto it : mp) {
            if (it.second > mid) { // Check if count is more than half the array size
                ans = it.first;
            }
        }
        
        // Return the majority element found by the map method
        return ans;

      
        // Approach 3: Moore’s Voting Algorithm
        
        // Size of the given array
        int n = nums.size();
        int cnt = 0; // Count for current candidate
        int el; // Current candidate for majority element
        
        // Applying the Moore's Voting Algorithm
        for (int i = 0; i < n; i++) {
            if (cnt == 0) {
                cnt = 1; // Start a new candidate
                el = nums[i];
            } else if (el == nums[i]) {
                cnt++; // Increment count if current element matches candidate
            } else {
                cnt--; // Decrement count if current element does not match candidate
            }
        }

        // Verifying if the candidate is actually the majority element
        int cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == el) cnt1++; // Count occurrences of candidate
        }

        // Check if candidate is the majority element
        if (cnt1 > (n / 2)) return el;
        return -1; // Return -1 if no majority element found (should not happen by problem constraints)
    }
};
