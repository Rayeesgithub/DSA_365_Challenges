https://leetcode.com/problems/spiral-matrix/
//striver sheet

//Time Complexity: O(m x n) && Space Complexity: O(n) { Extra Space used for storing traversal in the ans array }.
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size(); // Number of rows in the matrix
        int col = matrix[0].size(); // Number of columns in the matrix

        int firstRow = 0; // Initial row index for the top boundary
        int lastRow = row - 1; // Initial row index for the bottom boundary
        int firstCol = 0; // Initial column index for the left boundary
        int lastCol = col - 1; // Initial column index for the right boundary

        vector<int> ans; // Vector to store the elements in spiral order
        int totalElement = row * col; // Total number of elements in the matrix
        int count = 0; // Counter to keep track of the number of elements added to the result

        while (count < totalElement) {
            // Traverse from left to right along the top boundary
            for (int i = firstCol; i <= lastCol && count < totalElement; i++) {
                ans.push_back(matrix[firstRow][i]);
                count++;
            }
            firstRow++; // Move the top boundary down

            // Traverse from top to bottom along the right boundary
            for (int i = firstRow; i <= lastRow && count < totalElement; i++) {
                ans.push_back(matrix[i][lastCol]);
                count++;
            }
            lastCol--; // Move the right boundary left

            // Traverse from right to left along the bottom boundary
            for (int i = lastCol; i >= firstCol && count < totalElement; i--) {
                ans.push_back(matrix[lastRow][i]);
                count++;
            }
            lastRow--; // Move the bottom boundary up

            // Traverse from bottom to top along the left boundary
            for (int i = lastRow; i >= firstRow && count < totalElement; i--) {
                ans.push_back(matrix[i][firstCol]);
                count++;
            }
            firstCol++; // Move the left boundary right
        }

        return ans; // Return the elements in spiral order
    }
};
