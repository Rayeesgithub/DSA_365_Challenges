//https://www.geeksforgeeks.org/problems/rotation4723/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=rotation
// striver sheet

//broute force
int findKRotation(vector<int> &arr) {
    int index = -1; 
    int ans = INT_MAX; 
    int n = arr.size();
 // Edge case: if the last element of the array is equal to n (assuming array is 0-indexed)
    if (arr[n - 1] == n) {
        return 0; // Return 0 because the array is not rotated
    }
  // Iterate through the array to find the minimum element and its index
    for (int i = 0; i < n; i++) {
        if (arr[i] < ans) { // If the current element is less than the minimum element found so far
            ans = arr[i]; // Update the minimum element
            index = i; // Update the index of the minimum element
        }
    }
    return index; // Return the index of the minimum element, which indicates the number of rotations
}


// broute force 2
int rotate(vector<int>&arr,int n,int target){
   int count=1; int ans=INT_MAX;
   for(int i=0; i<n; i++){
    if(arr[i]+1==arr[i+1]){
        count++;
    }
    else{
        break;
    }
   }
   return count;
}

// optimal-approach
int findKRotation(vector<int> &arr) {
        int ans=INT_MAX;
         int index=-1;
         
         int s=0; int e=arr.size()-1;
         while(s<=e){
             int mid=s+(e-s)/2;
      //search space is already sorted
        //then arr[low] will always be
        //the minimum in that search space:
             if(arr[s]<=arr[e]){
                 if(arr[s]<ans){
                     ans=arr[s];
                     index=s;
                 }
                 break;
             }
             //if left part is sorted:
             if(arr[s]<=arr[mid]){
                if(arr[s]<ans){
                    ans=arr[s];
                    index=s;
                }
                s=mid+1;  // Eliminate left half:
             }
             else{     //if right part is sorted:
                 if(arr[mid]<ans){
                      ans=arr[mid];
                    index=mid;
                 }
                 e=mid-1;   // Eliminate right half:
             }
         }
         return index;
    }
