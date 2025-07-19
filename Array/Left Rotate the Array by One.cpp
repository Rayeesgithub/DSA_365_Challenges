//Input: N = 5, array[] = {1,2,3,4,5}
Output: 2,3,4,5,1


  
// striver sheet
#include<bits/stdc++.h>
using namespace std;
// approach1

// Includes all standard C++ libraries (not recommended for production but okay for competitive programming)
vector<int> rotateArray(vector<int>& arr, int n) {
    // Function to rotate the array to the left by 1 position
    // Example: Input: [1, 2, 3, 4, 5] -> Output: [2, 3, 4, 5, 1]

    vector<int> temp(n);  // Create a temporary vector of same size as input array

    for(int i = 1; i <= n ; i++) {
        // Start from index 1 and shift each element to the left by 1
        temp[i - 1] = arr[i]; // Place arr[1] at temp[0], arr[2] at temp[1], etc.
    }

    temp[n - 1] = arr[0]; // Move the first element to the last position

    return temp; // Return the rotated array
}


// second approach
vector<int> rotateArray(vector<int>& arr, int n) {
    // Function to rotate the array to the left by 1 position
    // Example: Input: [1, 2, 3, 4] → Output: [2, 3, 4, 1]

    int temp = arr[0]; 
    // Store the first element temporarily (we'll move it to the end later)

    for (int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1]; 
        // Shift each element one position to the left
        // arr[0] = arr[1], arr[1] = arr[2], and so on
    }

    arr[n - 1] = temp;
    // Place the original first element at the end of the array

    return arr;
    // Return the updated (rotated) array
}

int main(){
  int arr[]={1,2,3,4,5};
  int n=sizeof(arr)/sizeof(arr[0]);
  leftRotate(arr,n);
  cout<<"after rotate"<<endl;
  for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
}
