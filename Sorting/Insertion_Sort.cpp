// Striver-sheet
Input:  nums = [7, 4, 1, 5, 3]  
Output:  [1, 3, 4, 5, 7]  




 #include<bits/stdc++.h>
using namespace std;

// Function to perform Insertion Sort
void InsertSort(vector<int>& arr) {   // (Name is BubbleSort but logic is Insertion Sort)

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
  InsertSort(arr);

  // Print sorted array
  for(int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }
}


dry run->
✅ Initial Array:[7, 4, 1, 5, 3]
 ⭐ Pass 1 → i = 1
key = 4, Left side = [7] (treated as sorted)

Compare with left:
j = 0 → arr[0] = 7
7 > 4 → shift 7 to the right

Array becomes:
[7, 7, 1, 5, 3]
Now j = -1 → stop
Insert key:  arr[j+1] = arr[0] = 4

Array after Pass 1:
[4, 7, 1, 5, 3]

 
 ⭐ Pass 2 → i = 2
key = 1
Left side = [4, 7]
Compare:
j = 1 → 7 > 1 → shift
[4, 7, 7, 5, 3]

j = 0 → 4 > 1 → shift
[4, 4, 7, 5, 3]

j = -1 → stop

Insert key at index 0:
Array after Pass 2:
[1, 4, 7, 5, 3]

 ⭐ Pass 3 → i = 3
key = 5
Left side = [1, 4, 7]

Compare:
j = 2 → 7 > 5 → shift
[1, 4, 7, 7, 3]
j = 1 → 4 (NOT > 5) → stop
Insert key at index j+1 = 2:

Array becomes:
[1, 4, 5, 7, 3]

 so on
...........
 
 
 
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

