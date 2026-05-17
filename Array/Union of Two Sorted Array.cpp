// GFG->Union of Two Sorted Arrays
// STRIVER SHEET

Input:
n = 10,m = 7.
arr1[] = {1,2,3,4,5,6,7,8,9,10}
arr2[] = {2,3,4,4,5,11,12}
Output: {1,2,3,4,5,6,7,8,9,10,11,12}
Explanation: 
Common Elements in arr1 and arr2  are:  2,3,4,5
Distnict Elements in arr1 are : 1,6,7,8,9,10
Distnict Elemennts in arr2 are : 11,12
Union of arr1 and arr2 is {1,2,3,4,5,6,7,8,9,10,11,12} 

  

// 1st approach-> using map fxn 
  Time Compleixty : O( (m+n)log(m+n) )(map insertion takes logN)  && Space Complexity : O(m+n)

  
vector<int> FindUnion(int arr1[], int arr2[], int n, int m) {

    // Map will store each number as key (unique) and count as value
    map<int, int> freq;

    // Insert all elements of arr1 into map
    for (int i = 0; i < n; i++)
        freq[arr1[i]]++;  // O(log n)

    // Insert all elements of arr2 into map
    for (int i = 0; i < m; i++)
        freq[arr2[i]]++;  // O(log m)

    vector<int> Union;

    // Now map contains each element only once (sorted order)
    for (auto &it : freq)
        Union.push_back(it.first);

    return Union;
}
;
}



// 2nd approach-> using set fxn
Time Compleixty : O( (m+n)log(m+n) ) && Space Complexity : O(m+n)

vector<int> FindUnion(int arr1[], int arr2[], int n, int m) {

    // Set automatically keeps ONLY unique values in sorted order
    set<int> s;

    // Insert arr1 elements
    for (int i = 0; i < n; i++)
        s.insert(arr1[i]);  // O(log n)

    // Insert arr2 elements
    for (int i = 0; i < m; i++)
        s.insert(arr2[i]);  // O(log m)

    vector<int> Union;

    // Extract elements from set into vector
    for (auto &it : s)
        Union.push_back(it);

    return Union;
}





//PATTERN->  Two pointer approach  
// Time Compleixty : O( (m+n)) && Space Complexity : O(m+n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find union of two sorted arrays using two pointers
    vector<int> findUnion(int arr1[], int arr2[], int n, int m) {
        // Vector to store union elements
        vector<int> Union;

        // Initialize two pointers for both arrays
        int i = 0, j = 0;

        // Loop until either pointer reaches the end
        while (i < n && j < m) {
            // If current element in arr1 is smaller
            if (arr1[i] < arr2[j]) {
                // Add element if union empty or different from last added
                if (Union.empty() || Union.back() != arr1[i])
                    Union.push_back(arr1[i]);
                i++;  // Move pointer in arr1
            }
            // If current element in arr2 is smaller
            else if (arr2[j] < arr1[i]) {
                // Add element if union empty or different from last added
                if (Union.empty() || Union.back() != arr2[j])
                    Union.push_back(arr2[j]);
                j++;  // Move pointer in arr2
            }
            else {
                // Elements are equal, add once if not duplicate
                if (Union.empty() || Union.back() != arr1[i])
                    Union.push_back(arr1[i]);
                i++; j++;  // Move both pointers
            }
        }

        // Append remaining elements from arr1
        while (i < n) {
            if (Union.empty() || Union.back() != arr1[i])
                Union.push_back(arr1[i]);
            i++;
        }

        // Append remaining elements from arr2
        while (j < m) {
            if (Union.empty() || Union.back() != arr2[j])
                Union.push_back(arr2[j]);
            j++;
        }

        // Return the final union vector
        return Union;
    }
};

int main() {
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {2, 3, 4, 4, 5, 11, 12};
    int n = 10, m = 7;

    Solution obj;
    vector<int> result = obj.findUnion(arr1, arr2, n, m);

    cout << "Union of arr1 and arr2 is: ";
    for (int val : result) cout << val << " ";
    return 0;
}

}
