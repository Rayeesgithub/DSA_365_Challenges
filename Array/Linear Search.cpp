Example 1:  
Input: arr[] = 1 2 3 4 5, num = 3  
Output: 2  `
Explanation: 3 is present at the 2nd index of the array.



Time=0(n) && space=0(1)
    
int search(int arr[], int n, int target)
{
    // Loop through the array to find the number
    for(int i = 0; i < n; i++)
    {
        // If the current element matches the number, return its index
        if(arr[i] == target)
            return i;
    }

    // If the number is not found, return -1
    return -1;
}
