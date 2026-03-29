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
    int main(){

    vector<int> arr = {2,3,1,9,3,1,3,9};

    unordered_set<int> seen;   // to track visited elements
    vector<int> result;

    for(int x : arr){

        // if element not seen before
        if(seen.find(x) == seen.end()){
            result.push_back(x);  // keep it
            seen.insert(x);       // mark as seen
        }
    }

    // print result
    for(int x : result){
        cout << x << " ";
    }
}


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
