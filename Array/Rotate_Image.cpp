https://leetcode.com/problems/rotate-image/
// striver sheet
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(); // Get the size of the matrix (n x n)
        
        // Brute Force Approach
        // Time Complexity: O(N*N)
        // Space Complexity: O(N*N)
        vector<vector<int>> rotate(n, vector<int>(n, 0)); // Create a new matrix to store the rotated result
        
        // Fill the new matrix with rotated values
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                rotate[j][n - i - 1] = matrix[i][j]; // Rotate the element to its new position
            }
        }
        
        matrix = rotate; // Update the original matrix with the rotated matrix

        // Optimal Approach
        // Time Complexity: O(N*N)
        // Space Complexity: O(1)
        
        // Transpose the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]); // Swap elements to transpose the matrix
            }
        }
        
        // Reverse each row of the matrix
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end()); // Reverse the elements in each row
        }
    }
};
int main() {
    vector < vector < int >> arr;
    arr =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate(arr);
    cout << "Rotated Image" << endl;
    for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[0].size(); j++) {
        cout << arr[i][j] << " ";
    }
    cout << "n";
    }

}
