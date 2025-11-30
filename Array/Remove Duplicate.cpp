//https://leetcode.com/problems/remove-duplicates-from-sorted-array/

Input: arr[]=[1,1,2,2,2,3,3]
Output: [1,2,3,_,_,_,_]
Explanation: Total number of unique elements are 3, i.e[1,2,3] and Therefore return 3 after assigning [1,2,3] in the beginning of the array.


//approach-1
Insert into set-> 	O(log n) per insert
n inserts -> O(n log n)
Time->  O(n log n) && space=O(n) (to store unique elements)
#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {1,1,2,2,2,3,3};
    int n = 7;

    // Set stores only unique elements (duplicates are ignored)
    set<int> st;

    // Insert all array elements into set
    for (int i = 0; i < n; i++) {
        st.insert(arr[i]);  // duplicates will not be added again
    }

    // Printing unique values
    for (int x : st) {
        cout << x << " ";
    }
    return 0;
}


// approach2
Time->  O(n log n) && space=O(n)   
    unordered_set (O(n) time)
int main() {
    int arr[] = {1,1,2,2,2,3,3};
    int n = 7;

    // Map will store element as key & its frequency as value
    map<int, int> mp;

    // Counting frequency of each element
    for (int i = 0; i < n; i++) {
        mp[arr[i]]++;  // increase count
    }

    // Printing only unique elements (keys of map)
    for (auto it : mp) {
        cout << it.first << " ";  // it.first = element
    }
    return 0;
}




//  approach 3
Time->  O(n) && space=O(1)
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
