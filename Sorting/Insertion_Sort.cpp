// Striver-sheet
Input:  nums = [7, 4, 1, 5, 3]  
Output:  [1, 3, 4, 5, 7]  




 #include<bits/stdc++.h>
using namespace std;

// Function to perform Insertion Sort
void BubbleSort(vector<int>& arr) {   // (Name is BubbleSort but logic is Insertion Sort)

  int n = arr.size();    
  // Loop starts from index 1 because we treat arr[0] as already sorted
  for(int i = 1; i < n; i++) {

    int curr = arr[i];     // Fetch current element to be inserted in correct place
    int j = i - 1;        // Start comparing with previous element

    // Move elements of arr[0..j] that are greater than curr, one position ahead
    while(j >= 0 && arr[j] > curr) {   // Compare current with sorted part

      arr[j + 1] = arr[j];   // Shift element to the right
      j--;                   // Move j one step left
    }

    // Insert key at the correct position found
    arr[j + 1] = curr;
  }
}

int main() {

  // Input array
  vector<int> arr = {13, 46, 24, 52, 20, 9, 8, 1};

  // Call sorting function
  BubbleSort(arr);

  // Print sorted array
  for(int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }
}




 
 
 
 
 
 // approach-2
 void insertionSort(int arr[], int n)
    {
        //code here
        for(int i=1; i<n; i++){
            //step1- fetch
            int key=arr[i];
            int j=i-1;
            for(;j>=0;j--){
                //compare
                if(arr[j]>key){
                    //shift
                    arr[j+1]=arr[j];
                }
                else{
                    break;
                }
            }
            // copy
            arr[j+1]=key;
        }

