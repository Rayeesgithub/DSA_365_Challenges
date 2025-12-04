
Example 1:
Input: [2,4,1,3,5]
Output: 3

Example 2:
Input: [2,5,1,7]
Output: 3.5



  Time=nlogn space=0(1)


#include <bits/stdc++.h>
using namespace std;

double findMedian(vector<int> &arr) {
    sort(arr.begin(), arr.end());  // Step 1: Sort the array
    int n = arr.size();

    // If n is odd → return middle element
    if (n % 2 != 0)
        return arr[n / 2];

    // If n is even → return average of two middle elements
    return (arr[n/2] + arr[n/2 - 1]) / 2.0;
}

int main() {
    vector<int> arr = {2, 5, 1, 7};
    cout << "Median = " << findMedian(arr);
}
