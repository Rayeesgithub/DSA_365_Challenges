Input 
1 2 3
4 5 6
7 8 9

OUTPUT
7 4 1
8 5 2
9 6 3
  
#include <vector>
#include <algorithm>
using namespace std;

void rotate90DegreesClockwise(vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    // STEP 1: Transpose the matrix (swap elements across the main diagonal)
    // Note: 'j' starts from 'i' so we don't swap elements back to their original places!
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    
    // STEP 2: Reverse each individual row
    for (int i = 0; i < n; i++) {        reverse(matrix[i].begin(), matrix[i].end());
    }
}

✅ STEP 3: Dry Run on Your Input
Input Matrix:
1 2 3
4 5 6
7 8 9

Phase 1: Transpose Loop Execution
We iterate through the upper triangle of the matrix and swap matrix[i][j] with matrix[j][i]:
Swap matrix[0][1] (2) with matrix[1][0] (4)
Swap matrix[0][2] (3) with matrix[2][0] (7)
Swap matrix[1][2] (6) with matrix[2][1] (8)

Matrix state after Step 1 (Transpose):
1 4 7
2 5 8
3 6 9

  Phase 2: Row Reversal Execution
Now we run a simple loop to reverse every row horizontally:

Reverse Row 0: [1, 4, 7] becomes [7, 4, 1]

Reverse Row 1: [2, 5, 8] becomes [8, 5, 2]

Reverse Row 2: [3, 6, 9] becomes [9, 6, 3]

Final Matrix State:
7 4 1
8 5 2
9 6 3
