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
