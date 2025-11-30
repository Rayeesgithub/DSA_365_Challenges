Example 1:  
Input: arr[] = {2, 5, 1, 3, 0}  
Output: 5  
Explanation:  
5 is the largest element in the array.

  //1st approach  
  Time=nlog(n) space=0(1)
int sortArr(vector<int>& arr) {
    // Sort the array in ascending order
    sort(arr.begin(), arr.end());
    
    // Return the last element (largest element) after sorting
    return arr[arr.size() - 1];
}


 
  // 2nd approach
  Time=0(N) space=0(1)

int largest(vector<int> &arr, int n)
{
    // Initialize maxi with the smallest possible integer
    int maxi = INT_MIN;

    // Loop through all elements of the array
    for(int i = 0; i < n; i++) {

        // If current element is greater than maxi
        // then update maxi
        if(arr[i] > maxi) {
            maxi = arr[i];
        }

        // Same as above in a shorter way:
        // maxi = max(maxi, arr[i]);
    }

    // After loop ends, maxi holds the largest value in the array
    return maxi;
}

