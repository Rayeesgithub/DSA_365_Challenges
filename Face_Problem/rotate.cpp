Input: N = 5, array[] = {1,2,3,4,5} K=2
Output: {3,4,5,1,2}
Explanation: Rotate the array to right by 2 elements.


#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 2;

    int n = arr.size();
    k = k % n; // in case k > n

    vector<int> rotated;

    // Add elements from index k to n-1
    for (int i = k; i < n; i++) {
        rotated.push_back(arr[i]);
    }

    // Add elements from index 0 to k-1
    for (int i = 0; i < k; i++) {
        rotated.push_back(arr[i]);
    }

    cout << "Rotated array: ";
    for (int num : rotated) {
        cout << num << " ";
    }

    return 0;
}
