Input:   {{1,2,3},
          {4,5,6},
          {7,8,9}}
Output:
        3 6 9 
        2 5 8 
        1 4 7 

// approach1-> time=0(n^2) && space=0(n^2)
void rotateAntiClockwise(vector<vector<int>>& arr) {

    int n = arr.size();  
    // n = number of rows = number of columns (square matrix)

    // Creating a new matrix of same size to store rotated result
    vector<vector<int>> rotated(n, vector<int>(n));

    // -----------------------------------------
    // STEP 1: Fill rotated matrix
    // -----------------------------------------
    for(int i = 0; i < n; i++){           // traverse each row
        for(int j = 0; j < n; j++){       // traverse each column

            // Move element to correct anti-clockwise position
            // Formula:
            //      rotated[n-1-j][i] = arr[i][j];
            rotated[n - 1 - j][i] = arr[i][j];
        }
    }

    // Copy rotated matrix back into original matrix
    arr = rotated;
}



// 2nd approach  time=0(n^2) && space=0(1)
 void rotateAntiClockwise(vector<vector<int>>& arr) {

    int n = arr.size();        // rows
    int m = arr[0].size();     // columns

    // -----------------------------------------
    // STEP 1: Transpose the matrix
    // Convert rows → columns
    // -----------------------------------------
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < m; j++){
            
            // Swap element at (i, j) with (j, i)
            swap(arr[i][j], arr[j][i]);
        }
    }

    // -----------------------------------------
    // STEP 2: Reverse rows order (column-wise reverse)
    // This completes anti-clockwise rotation
    // -----------------------------------------
    reverse(arr.begin(), arr.end());  
    // arr[0] becomes arr[last], etc.

    // -----------------------------------------
    // STEP 3: Print final rotated matrix
    // -----------------------------------------
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}


dry run->
input
1 2 3
4 5 6
7 8 9
Example after transpose:
1 4 7
2 5 8
3 6 9
After reversing row order:
3 6 9
2 5 8
1 4 7
