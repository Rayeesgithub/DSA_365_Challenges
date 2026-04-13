https://leetcode.com/problems/set-matrix-zeroes/

Input: matrix=[[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Explanation: Since matrix[2][2]=0.Therfore the 2nd column and 2nd row wil be set to 0.

Input: matrix=[[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output:[[0,0,0,0],[0,4,5,0],[0,3,1,0]]

    
// approach1-> Time Complexity: O(m × n) &&  Space Complexity: O(m + n
void setZeroes(vector<vector<int>>& matrix) {

    // n = number of rows, m = number of columns
    int n = matrix.size();
    int m = matrix[0].size();

    // row[i] = -1 → entire ith row should be converted to zero
    vector<int> row(n, 0);

    // col[j] = -1 → entire jth column should be converted to zero
    vector<int> col(m, 0);

    // --------------------------------------------------------
    // 1st Pass → Only mark rows and columns that contain a ZERO
    // --------------------------------------------------------
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            
            // If we find a zero at (i, j)
            if (matrix[i][j] == 0) {

                // Mark this entire row to be zeroed
                row[i] = -1;

                // Mark this entire column to be zeroed
                col[j] = -1;
            }
        }
    }

    // --------------------------------------------------------
    // 2nd Pass → Actual zeroing using the row[] & col[] markers
    // --------------------------------------------------------
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            // If the row or column is marked → make this cell zero
            if (row[i] == -1 || col[j] == -1) {
                matrix[i][j] = 0;
            }
        }
    }

    // Printing the final matrix
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


DRY RUN_>
    Step 1: Initialize marker arrays
row = [0, 0, 0]    // 3 rows
col = [0, 0, 0]    // 3 columns
    ⭐ FIRST PASS: Mark rows & columns that contain ZERO
  i= 1 , j=1   matrix[1][1]=0 YES ZERO → mark row 1 & col 1
    After the zero at (1,1):
    row = [0, -1, 0]
col = [0, -1, 0]
    ⭐ SECOND PASS: Convert marked rows/columns to ZERO
Row 0:

(0,0): row[0]=0, col[0]=0 → keep 1
(0,1): col[1]=-1 → MAKE ZERO
(0,2): ok

Row 0 becomes:
1 0 1

Row 1:
row[1] = -1 → whole row becomes zero
0 0 0

Row 2:
(2,0): ok
(2,1): col[1] = -1 → MAKE ZERO
(2,2): ok

Row 2 becomes:
1 0 1

🎉 FINAL MATRIX
1 0 1
0 0 0
1 0 1

        
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
                if (setRows.count(i)  || setColumns.count(j) ) { // Check if the row or column is in the set
                    matrix[i][j] = 0; // Set the element to zero
                }
            }
        }
    }
    
};


🔴DRY RUN
Input: matrix =
[
 [0,1,2,0],
 [3,4,5,2],
 [1,0,1,5]
]
🔶 STEP 1: Find all zero positions
| i | j | value | Action   |
| - | - | ----- | -------- |
| 0 | 0 | 0     | ✅ insert |
| 0 | 1 | 1     | -        |
| 0 | 2 | 2     | -        |
| 0 | 3 | 0     | ✅ insert |
| 1 | 0 | 3     | -        |
| 1 | 1 | 4     | -        |
| 1 | 2 | 5     | -        |
| 1 | 3 | 2     | -        |
| 2 | 0 | 1     | -        |
| 2 | 1 | 0     | ✅ insert |
| 2 | 2 | 1     | -        |
| 2 | 3 | 5     | -        |

🔷 After Step 1:
rows = {0, 2}
cols = {0, 1, 3}

👉 Meaning:

Rows to zero → 0 and 2
Columns to zero → 0, 1, 3

🔶 STEP 2: Update matrix
🔷 i = 0

Since rows.count(0) = 1 ✅
👉 Entire row becomes 0
  [0,0,0,0]

🔷 i = 1

Check each column:

j = 0
cols.count(0)=1 ✅ → 0
j = 1
cols.count(1)=1 ✅ → 0
j = 2
rows.count(1)=0 AND cols.count(2)=0 → keep 5
j = 3
cols.count(3)=1 ✅ → 0

👉 Row becomes:

[0,0,5,0]
🔷 i = 2

Since rows.count(2) = 1 ✅
👉 Entire row becomes 0

[0,0,0,0]
🔷 Final Output
[
 [0,0,0,0],
 [0,0,5,0],
 [0,0,0,0]
]
