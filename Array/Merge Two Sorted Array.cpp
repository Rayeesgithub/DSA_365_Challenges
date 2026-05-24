Input : nums1 = [-5, -2, 4, 5, 0, 0, 0], nums2 = [-3, 1, 8]
Output : [-5, -3, -2, 1, 4, 5, 8]
Explanation : The merged array is: [-5, -3, -2, 1, 4, 5, 8], where [-5, -2, 4, 5] are from nums1 and [-3, 1, 8] are from nums2





//approach1->Borute force
void mergeSortedArrays(vector<int>& arr1, vector<int>& arr2) {
    int n = arr1.size();
    int m = arr2.size();
    
    // Insert elements of arr2 into arr1 at correct position
    for(int i = 0; i < m; i++) {
        arr1.push_back(arr2[i]);
    }
    
    // Sort the combined array
    sort(arr1.begin(), arr1.end());
}


// optimal
#include <vector>
#include <algorithm>
using namespace std;

void mergeWithoutSpace(vector<int>& arr1, vector<int>& arr2) {
    int n = arr1.size();
    int m = arr2.size();
    
    // 1. Initialize pointers at the boundary intersection
    int i = n - 1; // Last element of arr1
    int j = 0;     // First element of arr2
    
    // 2. Traversal Loop: Swap out-of-order elements across arrays
    while (i >= 0 && j < m) {
        if (arr1[i] > arr2[j]) {
            swap(arr1[i], arr2[j]);
            i--; // Move backward in arr1 to check next largest
            j++; // Move forward in arr2 to check next smallest
        } 
        else {
            // Optimization: Since both arrays are already sorted, 
            // if arr1[i] <= arr2[j], then everything to the left of i 
            // is guaranteed to be smaller than everything to the right of j.
            break; 
        }
    }
    
    // 3. Final Step: Re-sort both arrays individually to fix inner placement
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
}
