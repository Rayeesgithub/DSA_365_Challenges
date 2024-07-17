//gfg
// striver sheet

// broute force 1 Time Complexity: O((n + m) * log(n + m))  Space Complexity: O(n + m)
 int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        vector<int>ans;
      
    // Copy elements from arr1 to ans
    for (int i = 0; i < n; i++) {
        ans.push_back(arr1[i]);
    }
    
    // Copy elements from arr2 to ans
    for (int i = 0; i < m; i++) {
        ans.push_back(arr2[i]);
    }
    
    // Sort the merged array
    sort(ans.begin(), ans.end());
    
    // Find the k-th element
    int res = ans[k - 1];
    
    return res;
    }
// broute force 2-> Time Complexity: O(m+n)  Space Complexity: O(m+n)
int kthElement(int arr1[], int arr2[], int n, int m, int k) {
    vector<int> ans; // Vector to store the merged elements from both arrays
    int i = 0; // Pointer for traversing arr1
    int j = 0; // Pointer for traversing arr2

    // Merge the arrays until one of them is fully traversed
    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) { // Compare current elements of arr1 and arr2
            ans.push_back(arr1[i]); // Add smaller element to ans
            i++; // Move pointer of arr1
        } else {
            ans.push_back(arr2[j]); // Add smaller element to ans
            j++; // Move pointer of arr2
        }
    }

    // Copy the remaining elements of arr1, if any
    while (i < n) {
        ans.push_back(arr1[i++]);
    }

    // Copy the remaining elements of arr2, if any
    while (j < m) {
        ans.push_back(arr2[j++]);
    }

    // Return the k-th element (1-indexed) from the merged array
    return ans[k - 1];
}

// optimal 1
int kthElement(vector<int> &a, vector<int>& b, int m, int n, int k) {
    int ele = -1;
    int cnt = 0; //counter
    //apply the merge step:
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (a[i] < b[j]) {
            if (cnt == k - 1) ele = a[i];
            cnt++;
            i++;
        }
        else {
            if (cnt == k - 1) ele = b[j];
            cnt++;
            j++;
        }
    }

    //copy the left-out elements:
    while (i < m) {
        if (cnt == k - 1) ele = a[i];
        cnt++;
        i++;
    }
    while (j < n) {
        if (cnt == k - 1) ele = b[j];
        cnt++;
        j++;
    }
    return ele;
}


//optimal -2
int kthElement(int arr1[], int arr2[], int n, int m, int k) {
    // Ensure arr1 is the smaller array to minimize the number of operations.
    if (n > m) return kthElement(arr2, arr1, m, n, k);

    // Initialize binary search bounds
    int low = max(0, k - m);
    int high = min(k, n);

    // Perform binary search
    while (low <= high) {
        // Calculate the cut points
        int cut1 = (low + high) / 2;
        int cut2 = k - cut1;

        // Determine the elements just before and just after the cuts
        int l1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
        int l2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];
        int r1 = (cut1 == n) ? INT_MAX : arr1[cut1];
        int r2 = (cut2 == m) ? INT_MAX : arr2[cut2];

        // Check if we have found the correct partition
        if (l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        } 
        // Adjust the search range
        else if (l1 > r2) {
            high = cut1 - 1;
        } 
        else {
            low = cut1 + 1;
        }
    }
    return -1; // This line should never be

