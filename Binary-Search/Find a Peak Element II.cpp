https://leetcode.com/problems/find-a-peak-element-ii/description/
striver sheet

// broute force
 vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int maxi=INT_MIN;
       vector<int>index(2,-1);
       
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size();j++){
                if(mat[i][j]>maxi){
                    maxi=mat[i][j];
                   index[0]=i;
                   index[1]=j;
                }
            }
        }
        return index;
    }

// optimal approach
// Function to find the maximum element in a specific column and return its index
int findMaxInColumn(vector<vector<int>>& mat, int n, int col) {
    int maxVal = -1;  // Initialize the maximum value to -1 (or a very small value)
    int index = -1;   // Initialize the index of the maximum value to -1
    for (int i = 0; i < n; i++) {  // Iterate through each row in the specified column
        if (mat[i][col] > maxVal) {  // If the current element is greater than maxVal
            maxVal = mat[i][col];  // Update maxVal to the current element
            index = i;  // Update index to the current row
        }
    }
    return index;  // Return the index of the maximum element in the column
}

// Function to find a peak element in the grid
vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int n = mat.size();  // Number of rows in the matrix
    int m = mat[0].size();  // Number of columns in the matrix
    int s = 0;  // Start of the column range for binary search
    int e = m - 1;  // End of the column range for binary search
    
    while (s <= e) {  // Perform binary search on columns
        int mid = (s + e) / 2;  // Find the middle column index
        int maxRowIndex = findMaxInColumn(mat, n, mid);  // Find the row index of the maximum element in the middle column
        
        int left = (mid - 1 >= 0) ? mat[maxRowIndex][mid - 1] : -1;  // Value to the left of the middle element, or -1 if out of bounds
        int right = (mid + 1 < m) ? mat[maxRowIndex][mid + 1] : -1;  // Value to the right of the middle element, or -1 if out of bounds

        // Check if the middle element is greater than both left and right elements
        if (mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid] > right) {
            return {maxRowIndex, mid};  // Return the position of the peak element
        } else if (mat[maxRowIndex][mid] < left) {  // If the left element is greater
            e = mid - 1;  // Move to the left half
        } else {  // If the right element is greater
            s = mid + 1;  // Move to the right half
        }
    }
    return {-1, -1};  // Return {-1, -1} if no peak element is found
}
