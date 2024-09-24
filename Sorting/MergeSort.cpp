#include<bits/stdc++.h>
using namespace std;

void Merge(int arr[], int s, int e) {
    int mid = (s + e) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    // Create temporary arrays for left and right parts
    int *left = new int[len1];
    int *right = new int[len2];

    // Fill the left array
    int k = s;
    for (int i = 0; i < len1; i++) {
        left[i] = arr[k++];
    }

    // Fill the right array
    k = mid + 1;
    for (int i = 0; i < len2; i++) {
        right[i] = arr[k++];
    }

    // Merge the two arrays back into the original array
    int leftIndex = 0, rightIndex = 0, mainArrayIndex = s;
    while (leftIndex < len1 && rightIndex < len2) {
        if (left[leftIndex] < right[rightIndex]) {
            arr[mainArrayIndex++] = left[leftIndex++];
        } else {
            arr[mainArrayIndex++] = right[rightIndex++];
        }
    }

    // Add the remaining elements from the left array
    while (leftIndex < len1) {
        arr[mainArrayIndex++] = left[leftIndex++];
    }

    // Add the remaining elements from the right array
    while (rightIndex < len2) {
        arr[mainArrayIndex++] = right[rightIndex++];
    }

    // Clean up dynamically allocated memory
    delete[] left;
    delete[] right;
}

void MergeSort(int arr[], int s, int e) {
    if (s >= e) return;
    
    int mid = (s + e) / 2;
    MergeSort(arr, s, mid); // left part sort kr dega
    MergeSort(arr, mid + 1, e); // right part Sort kr dega
    Merge(arr, s, e);
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    MergeSort(arr, 0, n - 1);
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}
