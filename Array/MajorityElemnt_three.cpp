https://leetcode.com/problems/majority-element-ii/
Example 1:  
Input: nums = [1, 2, 1, 1, 3, 2]  
Output: [1]  
Explanation: Here, n / 3 = 6 / 3 = 2.  
Therefore, the elements appearing 3 or more times are: [1].





    

// Approach 1: Brute Force Time = O(n^2), Space = O(1)

vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans;     // To store result (max 2 elements possible for n/3 rule)

    // ----------------------------
    // TRY every element one by one
    // ----------------------------
    for (int i = 0; i < n; i++) {

        // To avoid counting same number again
        // If ans empty OR nums[i] is NOT equal to first stored element, then check
        if (ans.size() == 0 || ans[0] != nums[i]) {
            
            int cnt = 0;   // count frequency of nums[i]

            // Count how many times nums[i] appears
            for (int j = 0; j < n; j++) {
                if (nums[j] == nums[i]) {
                    cnt++;
                }
            }

            // Check if frequency > n/3
            if (cnt > (n / 3))
                ans.push_back(nums[i]);    // Add it to answer
        }

        // Maximum possible majority elements = 2
        if (ans.size() == 2) break;
    }

    return ans;
}

       
✅ Approach 2: Hashmap (Time = O(n), Space = O(n))
// Approach 2: Using Hashmap

vector<int> Majority(vector<int>& arr, int n) {

    unordered_map<int, int> mp;     // Stores frequency of each number
    vector<int> ans;                // To store final results

    // Count frequency of every element
    for (int i = 0; i < n; i++) {
        mp[arr[i]]++;
    }

    // Check which elements occur more than n/3 times
    for (auto it : mp) {
        if (it.second > n / 3) {
            ans.push_back(it.first);
        }
    }

    return ans;
}
