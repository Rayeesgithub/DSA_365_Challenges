//gfg
// striver

// Function to count the number of elements in the matrix less than or equal to 'mid'
int countLessEqual(vector<vector<int>> &matrix, int mid, int R, int C) {
    int count = 0; // Initialize count of elements
    for (int i = 0; i < R; i++) { // Iterate over each row
        // Use upper_bound to find the number of elements less than or equal to 'mid'
        count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
    }
    return count; // Return the count of elements
}

// Function to find the median of the matrix
int median(vector<vector<int>> &matrix, int R, int C) {
    int low = 0; // Minimum possible value in the matrix (assuming non-negative elements)
    int high = 2000; // Maximum possible value in the matrix (can be adjusted as needed)

    while (low <= high) { // Perform binary search on the value range
        int mid = low + (high - low) / 2; // Calculate the mid value of the current range
        int count = countLessEqual(matrix, mid, R, C); // Get the count of elements <= mid

        if (count <= (R * C) / 2) { // If count is less than or equal to half the total elements
            low = mid + 1; // Move to the upper half
        } else { // If count is more than half the total elements
            high = mid - 1; // Move to the lower half
        }
    }
    return low; // 'low' will be the median value after the loop
}
