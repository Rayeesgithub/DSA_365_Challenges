 //striver sheet

Example 1:
Input: N = 5, array[] = {5,4,3,2,1}
Output: 1,2,3,4,5
Explanation: After sorting we get 1,2,3,4,5


    
T.C= best-case o(n) && worst-case=0(n^2) && space=(1)

    #include<bits/stdc++.h>
using namespace std;

// Function to perform Bubble Sort
void BubbleSort(vector<int>& arr) {
    
    int n = arr.size();  // Store array size

    // Outer loop → runs n-1 times
    // After each full pass, the largest element moves to its correct position
    for(int i = 0; i < n - 1; i++) {

        // Inner loop → compares adjacent elements
        // j runs only till n-i-1 because last i elements are already sorted
        for(int j = 0; j < n - i - 1; j++) {

            // If current element is greater than next element, swap them
            if(arr[j] > arr[j + 1]) {

                // Swap - smaller element comes forward
                swap(arr[j], arr[j + 1]);

                /*
                // Manual swap code (same effect as swap())
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                */
            }
        }
    }
}

int main() {

    // Input vector
    vector<int> arr = {13, 46, 24, 52, 20, 9, 8, 1};

    // Call Bubble Sort function
    BubbleSort(arr);

    // Print sorted array
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
}

dry run->
Initial Array:
[5, 4, 3, 2, 1]
✅ Pass 1 (i = 0)
Compare adjacent elements:
| Comparison | Swap? | Array After       |
| ---------- | ----- | ----------------- |
| 5 > 4      | Yes   | `[4, 5, 3, 2, 1]` |
| 5 > 3      | Yes   | `[4, 3, 5, 2, 1]` |
| 5 >2      | Yes   | `[4, 3, 2, 5, 1]` |
| 5 > 1      | Yes   | `[4, 3, 2, 1, 5]` |
    ➡ Largest element 5 moved to last

✅ Your Doubt
"n = 5 and condition is j < n - i - 1
For i = 0 → j < 5 - 0 - 1 → j < 4
So j runs: 0,1,2,3
There is NO j = 4  So how do we compare the last element (1) with 5?"

    ✅ Correct Explanation
👉 Bubble sort does NOT compare the last element ALONE.
👉 It compares pairs of adjacent elements using:
arr[j] and arr[j+1].
So even though j goes only up to 3,
we still compare index 3 with 4 using arr[j+1]=arr[3+1]

    ✅ Pass 2 (i = 1)
Last element already sorted, so check till 3rd index only
| Comparison | Swap? | Array After       |
| ---------- | ----- | ----------------- |
| 4 & 3      | Yes   | `[3, 4, 2, 1, 5]` |
| 4 & 2      | Yes   | `[3, 2, 4, 1, 5]` |
| 4 & 1      | Yes   | `[3, 2, 1, 4, 5]` |

    ✅ Pass 3 (i = 2)
Check till index 2 only.
    | Comparison | Swap? | Array After       |
| ---------- | ----- | ----------------- |
| 3 & 2      | Yes   | `[2, 3, 1, 4, 5]` |
| 3 & 1      | Yes   | `[2, 1, 3, 4, 5]` |

  ✅ Pass 4 (i = 3)

Check only first two elements.
| Comparison | Swap? | Array After       |
| ---------- | ----- | ----------------- |
| 2 & 1      | Yes   | `[1, 2, 3, 4, 5]` |





    // Another approach Improve performance 
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        // Track if any swapping happens in this pass
        bool swapped = false;
        // Last i elements are already sorted
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap if the element is greater than the next element
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // If no elements were swapped in this pass, the array is already sorted
        if (!swapped) break;
    }
}


