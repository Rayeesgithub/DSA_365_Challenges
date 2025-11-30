Input: nums = [1, 2, 3, 4, 5]  
Output: [2, 3, 4, 5, 1]  
Explanation: Initially, nums = [1, 2, 3, 4, 5]  
Rotating once to the left results in nums = [2, 3, 4, 5, 1].


  

// Approach 1: Using a temporary array
Time Complexity: O(n) && Space Complexity: O(n)
vector<int> rotateArray(vector<int>& arr, int n) {

    vector<int> temp(n);   // temp array to store rotated result

    // Start shifting elements one position to the left
    for(int i = 1; i < n; i++) {
        temp[i - 1] = arr[i];  
        // Example:
        // arr = [1,2,3,4,5]
        // temp becomes: [2,3,4,5, _ ]
    }

    // Move the first element to the last position
    temp[n - 1] = arr[0];  
    // temp = [2,3,4,5,1]

    return temp;  // return the rotated array
}





// second approach
// Approach 2: In-place left rotation (no extra array used)
Time Complexity: O(n) && Space Complexity: O(1)
  
vector<int> rotateArray(vector<int>& arr, int n) {

    int temp = arr[0];  
    // Store the first element because it will be overwritten
    // Example: arr = [1,2,3,4,5], temp = 1

    // Shift all elements one position left
    for (int i = 1; i < n; i++) {
        arr[i - 1] = arr[i];
        // After loop:
        // arr = [2,3,4,5,5]
    }

    // Put the first element at the end
    arr[n - 1] = temp;
    // arr = [2,3,4,5,1]

    return arr;
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
