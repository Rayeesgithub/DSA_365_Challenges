// TCS NQT Striver
Input: [8 7 1 6 5 9]
Output: [1 5 6 9 8 7]
Explanation: First three elements are in the ascending order and next three elements are in the descending order.


Time=O(n log n) && space=0(1)

   #include<bits/stdc++.h>
using namespace std;

int main() {

    vector<int> arr = {8, 7, 1, 2, 6, 5, 9};

    // Sort the array in increasing order
    // Sorting takes O(n log n) time
    sort(arr.begin(), arr.end());

    // -------------------------------------------
    // Print the first half of the sorted array 
    // (from smallest elements)
    // -------------------------------------------
    for (int i = 0; i < arr.size() / 2; i++) {
        cout << arr[i] << " ";
    }

    // -------------------------------------------
    // Print the second half of the array 
    // but in reverse (from largest elements)
    // -------------------------------------------
    for (int i = arr.size() - 1; i >= arr.size() / 2; i--) {
        cout << arr[i] << " ";
    }
}
