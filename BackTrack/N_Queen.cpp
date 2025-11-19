Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

#include<bits/stdc++.h>
using namespace std;

// Track which rows already contain a Queen
unordered_map<int,bool> rowcheck;

// Track upper-left diagonals (↖ direction)
// Formula: (n-1 + col - row)
unordered_map<int,bool> upperLeftDiagonal;

// Track bottom-left diagonals (↙ direction)
// Formula: (row + col)
unordered_map<int,bool> bottomLeftDiagonal;


// -------------------------
// STORE SOLUTION
// -------------------------
void storeSolution(vector<vector<char>>&board,int n,vector<vector<string>>&ans){

    vector<string> temp;

    // Convert board (2D char) → vector<string>
    for(int i=0; i<n; i++) {
        string output = "";
        for(int j=0; j<n; j++) {
            output.push_back(board[i][j]);
        }
        temp.push_back(output);
    }

    // Store in final answer list
    ans.push_back(temp);
}


// -------------------------
// CHECK IF POSITION SAFE
// -------------------------
bool isSafe(int row,int col,vector<vector<char>>&board,int n){

    // Row already has a Queen
    if(rowcheck[row] == true){
        return false;
    }

    // Upper-left diagonal already has a Queen
    if(upperLeftDiagonal[n-1 + col - row] == true){
        return false;
    }

    // Bottom-left diagonal already has a Queen
    if(bottomLeftDiagonal[row + col] == true){
        return false;
    }

    return true; // Safe position
}


// -------------------------
// SOLVE N-QUEEN USING BACKTRACKING
// -------------------------
void solveNQueen(vector<vector<char>>&board,int n,int col,vector<vector<string>>&ans){

    // BASE CASE: All columns filled → valid solution
    if(col >= n){
        storeSolution(board,n,ans);
        return;
    }

    // TRY placing queen in each row for this column
    for(int row = 0; row < n; row++){

        if(isSafe(row, col, board, n)){

            // Place Queen
            board[row][col] = 'Q';

            // Mark row & diagonals as occupied
            rowcheck[row] = true;
            upperLeftDiagonal[n-1 + col - row] = true;
            bottomLeftDiagonal[row + col] = true;

            // Recurse for next column
            solveNQueen(board, n, col + 1, ans);

            // BACKTRACK → undo the placement
            board[row][col] = '.';
            rowcheck[row] = false;
            upperLeftDiagonal[n-1 + col - row] = false;
            bottomLeftDiagonal[row + col] = false;
        }
    }
}



// -------------------------
// MAIN FUNCTION
// -------------------------
int main() {
    int n = 4;
    int col = 0;

    // Create empty board filled with '.'
    vector<vector<char>> board(n, vector<char>(n,'.'));

    vector<vector<string>> ans;

    // Start solving from column 0
    solveNQueen(board, n, col, ans);

    // Print all solutions
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[0].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
