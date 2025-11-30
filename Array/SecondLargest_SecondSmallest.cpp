https://takeuforward.org/data-structure/find-second-smallest-and-second-largest-element-

Example 1:  
Input: [1, 2, 4, 7, 7, 5]  
Output:  
Second Smallest : 2  
Second Largest : 5  
Explanation:  The elements are sorted as 1, 2, 4, 5, 7, 7.  
Hence, the second smallest element is 2, and the second largest element is 5.


// apprach 1
Time=O(n) + O(n) = O(n)  && space= O(1)

void getElements(int arr[], int n)
{
    // If array has 0 or 1 element → second smallest and second largest cannot exist
    if (n == 0 || n == 1)
        cout << -1 << " " << -1 << endl;

    // smallest and second smallest (start with max value)
    int small = INT_MAX, second_small = INT_MAX;

    // largest and second largest (start with min value)
    int large = INT_MIN, second_large = INT_MIN;

    int i;

    // -----------------------------
    // STEP 1: Find smallest and largest elements
    // -----------------------------
    for (i = 0; i < n; i++)
    {
        // Update smallest value
        small = min(small, arr[i]);

        // Update largest value
        large = max(large, arr[i]);
    }

    // -----------------------------
    // STEP 2: Find second smallest and second largest
    // -----------------------------
    for (i = 0; i < n; i++)
    {
        // For second smallest:
        // Check arr[i] should be smaller than second_small AND not equal to smallest
        if (arr[i] < second_small && arr[i] != small)
            second_small = arr[i];

        // For second largest:
        // Check arr[i] should be larger than second_large AND not equal to largest
        if (arr[i] > second_large && arr[i] != large)
            second_large = arr[i];
    }

    // Print the results
    cout << "Second smallest is " << second_small << endl;
    cout << "Second largest is " << second_large << endl;
}




/ / approach->2
  int secondSmallest(int arr[],int n)
{
    if(n<2)
        return -1;
    int small = INT_MAX;
    int second_small = INT_MAX;
    int i;
    for(i = 0; i < n; i++) 
    {
       if(arr[i] < small)
       {
          second_small = small;
          small = arr[i];
       }
       else if(arr[i] < second_small && arr[i] != small)
       {
          second_small = arr[i];
       }
    }
   return second_small;     
}
int secondLargest(int arr[],int n)
{
	if(n<2)
	return -1;
    int large=INT_MIN,second_large=INT_MIN;
    int i;
    for (i = 0; i < n; i++) 
    {
        if (arr[i] > large) 
        {
            second_large = large;
            large = arr[i];
        }
 
        else if (arr[i] > second_large && arr[i] != large) 
        {
            second_large = arr[i];
        }
    }
    return second_large;                
}
