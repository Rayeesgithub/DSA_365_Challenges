Example 1:
Input: N = 6, array[] = {13,46,24,52,20,9}
Output: 9,13,20,24,46,52
Explanation: After sorting the array is: 9, 13, 20, 24, 46, 52

Example 2:
Input: N=5, array[] = {5,4,3,2,1}
Output: 1,2,3,4,5
Explanation: After sorting the array is: 1, 2, 3, 4, 5




// Time=O(n²) && space=0(1)



#include<bits/stdc++.h>
using namespace std;

// Function to perform Selection Sort
void selectionSort(vector<int>& arr){

    // Outer loop: runs n-1 times (for each position in array)
    for(int i = 0; i < arr.size() - 1; i++){

        int miniIndex = i;  
        // Assume the current index 'i' has the minimum element

        // Inner loop: find the minimum element in the unsorted part
        for(int j = i + 1; j < arr.size(); j++){

            // If a smaller element is found, update miniIndex
            if(arr[j] < arr[miniIndex]){
                miniIndex = j;
            }
        }

        // Swap the smallest found element with element at index 'i'
        swap(arr[i], arr[miniIndex]);

        /* 
        // Same swap can be written manually like this:
        int temp = arr[miniIndex];
        arr[miniIndex] = arr[i];
        arr[i] = temp;
        */
    }
}

int main() {

    // Input array
    vector<int> arr = {13, 46, 24, 52, 20, 9, 8, 2};

    // Call selection sort
    selectionSort(arr);

    // Print sorted array
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
}






// dry run

Initial Array:

[5, 4, 3, 2, 1]
   
    Pass 1:  i = 0

miniIndex = 0 → value = 5

Compare with all elements:
| j | arr[j] | miniIndex | Why            |
| - | ------ | --------- | -------------- |
| 1 | 4      | 1         | 4 < 5 → update |
| 2 | 3      | 2         | 3 < 4 → update |
| 3 | 2      | 3         | 2 < 3 → update |
| 4 | 1      | 4         | 1 < 2 → update |

    ✔ Minimum element found = 1 at index 4

➡ Swap arr[0] and arr[4]

Array becomes:
[1, 4, 3, 2, 5]
......
......
    so on

    
