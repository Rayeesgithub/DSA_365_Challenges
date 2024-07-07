https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-occurrence
 //striver

//broute force
int count(int arr[], int n, int x) {
	    // code here
	   int count=0;
	    broute force
	    for(int i=0; i<n;i++){
	        if(arr[i]==x){
	            count++;
	        }
	    }
	    return count;
	  }

// optimal approach
// Function to find the last occurrence of x in the array
int lastOcc(int arr[], int n, int x) {
    int ans = -1; 
    int s = 0; 
    int e = n - 1; 
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (arr[mid] == x) { // If the element at mid is equal to x
            ans = mid; // Update the answer to the current mid
            s = mid + 1; // Move to the right half to find the last occurrence
        } else if (arr[mid] < x) { // If the element at mid is less than x
            s = mid + 1; // Move to the right half
        } else { // If the element at mid is greater than x
            e = mid - 1; // Move to the left half
        }
    }
    return ans; // Return the index of the last occurrence
}

// Function to find the first occurrence of x in the array
int firstOcc(int arr[], int n, int x) {
    int ans = -1; 
    int s = 0; 
    int e = n - 1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (arr[mid] == x) { // If the element at mid is equal to x
            ans = mid; // Update the answer to the current mid
            e = mid - 1; // Move to the left half to find the first occurrence
        } else if (arr[mid] < x) { // If the element at mid is less than x
            s = mid + 1; // Move to the right half
        } else { // If the element at mid is greater than x
            e = mid - 1; // Move to the left half
        }
    }
    return ans; // Return the index of the first occurrence
}

// Function to count the number of occurrences of x in the array
int count(int arr[], int n, int x) {
    int first = firstOcc(arr, n, x); // Find the first occurrence of x
    if (first == -1) {
        return 0; // If x is not present in the array, return 0
    }
    int last = lastOcc(arr, n, x); // Find the last occurrence of x
    return last - first + 1; // Calculate the number of occurrences
}
