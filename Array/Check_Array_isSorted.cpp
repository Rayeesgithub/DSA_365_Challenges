Example 1:
Input: N = 5, array[] = {1,2,3,4,5}
Output: True.
Explanation: The given array is sorted i.e Every element in the array is smaller than or equals to its next values, So the answer is True.

Example 2:
Input: N = 5, array[] = {5,4,6,7,8}
Output: False.

//Brute Force
Time Complexity: O(N^2),
Space Complexity: O(1),
  
  // Function to check if the array is sorted
bool isSorted(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // If any element is smaller than the previous one, return false
            if (arr[j] < arr[i]) 
                return false;
        }
    }

    return true; // Return true if no unsorted elements are found
}


// optimal Approach
Time Complexity: O(N), space=0(1)

// Function to check if the array is sorted
bool isSorted(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1])  // If any element is smaller than the previous one, return false
            return false;
    }

    return true;  // Return true if the array is sorted
}
