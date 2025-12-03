Input : N=7,arr[]={3,2,8,5,1,4,23}
Output : {1,2,3,4,5,8,23}
Explanation : Given array is sorted in non-decreasing order.



  🔹 1. BREAK (Divide the array)
  Split the array into 2 halves again and again
2. Recursion will sort both halves automatically.

Let recursion sort the left half

Let recursion sort the right half
(3) create length llen2, len2 with dynamic array
(4)Merge the two sorted halves




  #include<bits/stdc++.h>
using namespace std;

// Function to merge two sorted halves of the array
void merge(vector<int>& arr, int s, int e) {

    int mid = (s + e) / 2;  // middle point of array

    // length of left half: from s to mid
    int len1 = mid - s + 1;

    // length of right half: from mid+1 to e
    int len2 = e - mid;

    // create dynamic arrays to store the left and right halves
    int *left = new int[len1];
    int *right = new int[len2];

    // copy elements into left array
    int k = s;   // starting index of left half in original array
    for (int i = 0; i < len1; i++) {
        left[i] = arr[k];
        k++;
    }

    // copy elements into right array
    k = mid + 1;  // starting index of right half
    for (int i = 0; i < len2; i++) {
        right[i] = arr[k++];
    }

    // Now merge both sorted arrays into the original array

    int leftIndex = 0;   // pointer for left array
    int rightIndex = 0;  // pointer for right array
    int mainIndex = s;   // pointer for original array

    // Compare elements of both arrays and place the smaller one
    while (leftIndex < len1 && rightIndex < len2) {
        if (left[leftIndex] < right[rightIndex]) {
            arr[mainIndex++] = left[leftIndex++];
        } else {
            arr[mainIndex++] = right[rightIndex++];
        }
    }

    // If any elements are left(remaining)  in left array, copy them
    while (leftIndex < len1) {
        arr[mainIndex++] = left[leftIndex++];
    }

    // If any elements are left in right array, copy them
    while (rightIndex < len2) {
        arr[mainIndex++] = right[rightIndex++];
    }

    // free dynamic memory (good practice)
    delete[] left;
    delete[] right;
}

// Recursive Merge Sort function
void mergeSort(vector<int>& arr, int s, int e) {

    // base case: single element is already sorted
    if (s >= e) {
        return;
    }

    // find mid
    int mid = (s + e) / 2;

    // recursively sort left half
    mergeSort(arr, s, mid);

    // recursively sort right half
    mergeSort(arr, mid + 1, e);

    // merge both sorted halves
    merge(arr, s, e);
}

int main() {

    vector<int> arr = {7, 3, 2, 16, 24, 4, 11, 9};

    int n = arr.size();
    int s = 0;
    int e = n - 1;

    mergeSort(arr, s, e); // apply merge sort

    // print sorted array
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
}


✅dry run-> 
Input:[3, 2, 8, 5, 1, 4, 23]
    ✅ STEP 1 — Full Splitting Phase
(We split until every element becomes a single element)

Split 1:

[3, 2, 8, 5, 1, 4, 23]
→ left: [3, 2, 8, 5]
→ right: [1, 4, 23]

   ⬅️ Split Left [3, 2, 8, 5]

→ left: [3, 2]
→ right: [8, 5]

Split [3,2]

→ [3] and [2]
Merge → [2,3]

Split [8,5]

→ [8] and [5]
Merge → [5,8]

Merge [2,3] and [5,8]

Sorted → [2,3,5,8]

➡️Split Right [1, 4, 23]

→ left: [1,4]
→ right: [23]

Split [1,4]

→ [1] and [4]
Merge → [1,4]

Merge [1,4] and [23]

Sorted → [1,4,23]


🚀 Final Merge

Merge big halves:
Left: [2,3,5,8]
Right: [1,4,23]

🔄 STEP 2 — Final Merge Dry Run
| Left | Right | Pick   |
| ---- | ----- | ------ |
| 2    | 1     | **1**  |
| 2    | 4     | **2**  |
| 3    | 4     | **3**  |
| 5    | 4     | **4**  |
| 5    | 23    | **5**  |
| 8    | 23    | **8**  |
| —    | 23    | **23** |


🎉 Final Sorted Array:
[1, 2, 3, 4, 5, 8, 23]
