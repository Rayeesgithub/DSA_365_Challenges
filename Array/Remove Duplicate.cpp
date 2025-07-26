//https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// striver sheet
//approach-1
int removeDuplicates(vector<int>& nums) {
    // Step 1: Create a set to store only unique elements
    set<int> st;

    // Step 2: Insert each element of nums into the set
    // Set automatically removes duplicates and keeps the elements sorted
    for (int i = 0; i < nums.size(); i++) {
        st.insert(nums[i]);  // e.g., nums = [1, 1, 2, 2, 3] => st = {1, 2, 3}
    }

    // Step 3: Replace the beginning of nums with the unique elements from the set
    int i = 0;
    for (auto it : st) {
        nums[i++] = it;  // nums = [1, 2, 3, ?, ?, ...]
    }

    // Step 4: Return the number of unique elements
    return st.size();  // In this example, returns 3
}



int main() {
    vector<int> arr = {5, 3, 2, 3, 5, 1, 4, 2};

    // Use map instead of unordered_map
    map<int, int> mp;

    // Count occurrences
    for (int i = 0; i < arr.size(); i++) {
        mp[arr[i]]++;
    }

    // Print unique elements in sorted order
    for (auto it : mp) {
        cout << it.first << " ";
    }

    return 0;
}



//print


// second approach
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // If the array is empty, return 0
        if (nums.size() == 0) return 0;

        int i = 0;  // Pointer to place unique elements

        // Start loop from the second element
        for (int j = 1; j < nums.size(); j++) {
            // If the current element is different from the last unique one
            if (nums[j] != nums[i]) {
                i++;              // Move the unique index forward
                nums[i] = nums[j]; // Copy current unique value to the correct position
            }
        }

        // The number of unique elements is (i + 1)
        return i + 1;
    }
};
