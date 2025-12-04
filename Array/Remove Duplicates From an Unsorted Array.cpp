//striver sheet NQT


Input: arr[]={2,3,1,9,3,1,3,9}
Output: {2,3,1,9}
Explanation: Removed all the duplicate elements.






// Remove duplicates from array
// Approach 1 -> Using set (Time: O(n log n), Space: O(n)) 
// Approach 2 -> Using unordered_map (Time: O(n), Space: O(n))

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n = 8;
    int arr[n] = {2, 3, 1, 9, 3, 1, 3, 9};

    // -------------------------
    // APPROACH 1: Using set
    // -------------------------
    // set stores only unique elements (automatically removes duplicates)
    // also stores them in sorted order
    set<int> st;

    // Insert all array elements into set
    for (int i = 0; i < n; i++) {
        st.insert(arr[i]);   // duplicates automatically ignored
    }

    // Print unique elements
    cout << "Approach 1 Output: ";
    for (auto it : st) {
        cout << it << " ";   // elements printed in sorted order
    }
    cout << endl;


    // -------------------------
    // APPROACH 2: Using unordered_map
    // -------------------------
    // unordered_map helps check if element is seen before in O(1) average time
    unordered_map<int, int> mp;

    cout << "Approach 2 Output: ";
    for (int i = 0; i < n; i++) {

        // If element appears for the first time
        if (mp.find(arr[i]) == mp.end()) {
            cout << arr[i] << " ";   // print the element
            mp[arr[i]]++;            // mark as visited
        }
    }
}
