//https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=row-with-max-1s
// striver 

// broute force
// Initialize variables to keep track of the maximum number of 1s found
// and the index of the row containing that maximum number.
int cnt_max = 0;
int index = -1;

// Traverse the matrix row by row.
for (int i = 0; i < n; i++) {
    // Initialize a counter for the number of 1s in the current row.
    int cnt_ones = 0;
    
    // Traverse each element of the current row.
    for (int j = 0; j < m; j++) {
        // Add the value of the current element to the counter.
        // This works because the elements are either 0 or 1.
        cnt_ones += matrix[i][j];
    }
    
    // After counting the 1s in the current row, check if this row
    // has more 1s than the previously recorded maximum.
    if (cnt_ones > cnt_max) {
        // If so, update the maximum count and the index of the row.
        cnt_max = cnt_ones;
        index = i;
    }
}

// Return the index of the row with the maximum number of 1s.
return index;
int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    int n = 3, m = 3;
    cout << "The row with maximum no. of 1's is: " <<
         rowWithMax1s(matrix, n, m) << '\n';
}


// optimal approach
int findone(vector<int> &arr, int m, int one) {
    int s = 0; 
    int e = m - 1;
    int ans = m; // Initialize to m, which means no 1 is found in the worst case.
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (arr[mid] >= one) { // Check if current element is 1 or more.
            ans = mid; // Update the answer to current mid.
            e = mid - 1; // Move to the left half.
        } else {
            s = mid + 1; // Move to the right half.
        }
    }
    return ans;
}

int rowWithMax1s(vector<vector<int>> &arr, int n, int m) {
    int max = 0; 
    int index = -1; // To store the row index with maximum 1s.
    for (int i = 0; i < n; i++) {
        int count_one = m - findone(arr[i], m, 1); // Calculate number of 1s in the current row.
        if (count_one > max) { // Update the maximum count and index if current row has more 1s.
            max = count_one;
            index = i;
        }
    }
    return index;
}
