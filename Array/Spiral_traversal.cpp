https://leetcode.com/problems/spiral-matrix/
//striver sheet


Input: Matrix[][] = { { 1, 2, 3, 4 },{ 5, 6, 7, 8 },{ 9, 10, 11, 12 },{ 13, 14, 15, 16 } }
Outhput: 1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10.
Explanation: The output of matrix in spiral form.


    
//Time Complexity: O(m x n) && Space Complexity: O(n) { Extra Space used for storing traversal in the ans array }.
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return {};
    
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> result;
    
    // 1. Initialize the 4 boundary pointers
    int top = 0;
    int bottom = rows - 1;
    int left = 0;
    int right = cols - 1;
    
    // 2. Loop until boundaries cross
    while (top <= bottom && left <= right) {
        
        // Direction 1: Move Left to Right along the current 'top' row
        for (int j = left; j <= right; j++) {
            result.push_back(matrix[top][j]);
        }
        top++; // Shrink the top boundary downward
        
        // Direction 2: Move Top to Bottom along the current 'right' column
        for (int i = top; i <= bottom; i++) {
            result.push_back(matrix[i][right]);
        }
        right--; // Shrink the right boundary inward
        
        // Direction 3: Move Right to Left along the current 'bottom' row
        if (top <= bottom) { // Safety check for single-row remnants
            for (int j = right; j >= left; j--) {
                result.push_back(matrix[bottom][j]);
            }
            bottom--; // Shrink the bottom boundary upward
        }
        
        // Direction 4: Move Bottom to Top along the current 'left' column
        if (left <= right) { // Safety check for single-column remnants
            for (int i = bottom; i >= top; i--) {
                result.push_back(matrix[i][left]);
            }
            left++; // Shrink the left boundary inward
        }
    }
    
    return result;
}
