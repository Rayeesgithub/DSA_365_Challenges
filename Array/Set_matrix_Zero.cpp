https://leetcode.com/problems/set-matrix-zeroes/
// striver sheet
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //1st approach->time Complexity : O(N*M)  Space Complexity : O(N+M)
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<int> row(n, 0); // Initialize a vector 'row' of size 'n' with all elements set to 0
        vector<int> col(m, 0); // Initialize a vector 'col' of size 'm' with all elements set to 0
        
        // First pass: identify all rows and columns that should be zeroed
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {  // If an element is zero
                    row[i] = -1; // Mark the ith row for zeroing
                    col[j] = -1; // Mark the jth column for zeroing
                }
            }
        }
         // Second pass: set the elements to zero based on the markers
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (row[i] == -1 || col[j] == -1) { // If the row or column is marked
                    matrix[i][j] = 0; // Set the element to zero
                }
            }
        }


        // broute for take input
        #include <bits/stdc++.h>
using namespace std;

void markRow(vector<vector<int>>& arr, int n, int m, int i) {
    for (int j = 0; j < m; j++) {
        if (arr[i][j] != 0) {
            arr[i][j] = -1;
        }
    }
}

void markCol(vector<vector<int>>& arr, int n, int m, int j) {
    for (int i = 0; i < n; i++) {
        if (arr[i][j] != 0) {
            arr[i][j] = -1;
        }
    }
}

void setZero(vector<vector<int>>& arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                markRow(arr, n, m, i);
                markCol(arr, n, m, j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == -1) {
                arr[i][j] = 0;
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter the number of rows: ";
    cin >> n;
    cout << "Enter the number of columns: ";
    cin >> m;

    vector<vector<int>>arr(n,vector<int>(m)); // Create a dynamic 2D vector based on user input

    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    setZero(arr, n, m);

    cout << "Resultant array:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

        
       // second approach  Time Complexity : O(N*M)  Space Complexity : O(N+M)
         int n = matrix.size();
        int m = matrix[0].size();
        // Create sets to store the indices of rows and columns that need to be zeroed
        unordered_set<int> setRows;    // Set to store the indices of rows to be zeroed
        unordered_set<int> setColumns; // Set to store the indices of columns to be zeroed

        // First pass: identify all rows and columns that should be zeroed
        for (int i = 0; i < n; i++) {       // Iterate through each row
            for (int j = 0; j < m; j++) {   // Iterate through each column
                if (matrix[i][j] == 0) {    // If an element is zero
                    setRows.insert(i);      // Add the row index to setRows
                    setColumns.insert(j);   // Add the column index to setColumns
                }
            }
        }

        // Second pass: set the elements to zero based on the sets
        for (int i = 0; i < n; i++) {       // Iterate through each row
            for (int j = 0; j < m; j++) {   // Iterate through each column
                if (setRows.count(i) > 0 || setColumns.count(j) > 0) { // Check if the row or column is in the set
                    matrix[i][j] = 0; // Set the element to zero
                }
            }
        }
    }
    
};
