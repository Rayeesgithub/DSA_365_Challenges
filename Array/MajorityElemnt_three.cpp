https://leetcode.com/problems/majority-element-ii/
//striver sheet
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size(); // Get the size of the input vector
        vector<int> ans; // List to store the majority elements

        // Approach 1: Brute Force
        for (int i = 0; i < n; i++) {
            // Check if nums[i] is not already a part of the answer
            if (ans.size() == 0 || ans[0] != nums[i]) {
                int cnt = 0; // Counter to count the frequency of nums[i]
                for (int j = 0; j < n; j++) {
                    // Counting the frequency of nums[i]
                    if (nums[j] == nums[i]) {
                        cnt++;
                    }
                }

                // Check if the frequency is greater than n/3
                if (cnt > (n / 3))
                    ans.push_back(nums[i]); // Add nums[i] to the answer list
            }

            // If we have found two majority elements, break
            if (ans.size() == 2) break;
        }

        // Approach 2: Using Hashmap
        unordered_map<int, int> mp; // Hashmap to store the frequency of each element
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++; // Increment the frequency of nums[i]
        }
        for (auto it : mp) {
            // Check if the frequency is greater than n/3
            if (it.second > n / 3) {
                ans.push_back(it.first); // Add the element to the answer list
            }
        }

        // Approach 3: Extended Boyer-Moore Voting Algorithm
        int cnt1 = 0, cnt2 = 0; // Counters for the two majority elements
        int el1 = INT_MIN; // Element 1
        int el2 = INT_MIN; // Element 2

        // Applying the Boyer-Moore Voting Algorithm
        for (int i = 0; i < n; i++) {
            if (cnt1 == 0 && el2 != nums[i]) {
                cnt1 = 1;
                el1 = nums[i]; // Update element 1
            }
            else if (cnt2 == 0 && el1 != nums[i]) {
                cnt2 = 1;
                el2 = nums[i]; // Update element 2
            }
            else if (nums[i] == el1) {
                cnt1++; // Increment the counter for element 1
            }
            else if (nums[i] == el2) {
                cnt2++; // Increment the counter for element 2
            }
            else {
                cnt1--; // Decrement both counters
                cnt2--;
            }
        }

        vector<int> ls; // List to store the final majority elements

        // Manually check if the stored elements in el1 and el2 are the majority elements
        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == el1) cnt1++; // Count the occurrences of el1
            if (nums[i] == el2) cnt2++; // Count the occurrences of el2
        }

        int mini = int(n / 3) + 1; // Minimum count required to be a majority element
        if (cnt1 >= mini) ls.push_back(el1); // Add el1 to the list if it is a majority element
        if (cnt2 >= mini) ls.push_back(el2); // Add el2 to the list if it is a majority element
        
        return ls; // Return the list of majority elements
    }
};
