Input: board = [["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."]
  ,["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]]

  Output: [["5","3","4","6","7","8","9","1","2"],
  ["6","7","2","1","9","5","3","4","8"],
  ["1","9","8","3","4","2","5","6","7"],
  ["8","5","9","7","6","1","4","2","3"],
  ["4","2","6","8","5","3","7","9","1"],
  ["7","1","3","9","2","4","8","5","6"],
  ["9","6","1","5","3","7","2","8","4"],
  ["2","8","7","4","1","9","6","3","5"],
  ["3","4","5","2","8","6","1","7","9"]]
Explanation: The input board is shown above and the only valid solution is shown below:




#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<char>>& board, int row, int col, int value) {

    // Check if placing `value` in board[row][col] is valid

    for(int i = 0; i < 9; i++) {

        // --- Row Check ---
        // If the number already exists in the same row → INVALID
        if(board[row][i] == value) {
            return false;
        }

        // --- Column Check ---
        // If the number already exists in the same column → INVALID
        if(board[i][col] == value) {
            return false;
        }

        // --- 3x3 Subgrid Check ---
        // Formula to move inside the block:
        // top-left of block = (row/3)*3 , (col/3)*3
        // then move 0..8 using i/3 and i%3
        if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == value) {
            return false;
        }
    }

    // If row, column and 3×3 grid are valid → safe to place
    return true;
}


bool sudokoSolver(vector<vector<char>>& board) {

    // Loop through every cell of the board
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {

            // If cell is empty ('.'), we need to fill a number 1–9
            if(board[i][j] == '.') {

                // Try every digit from '1' to '9'
                for(char c = '1'; c <= '9'; c++) {

                    // Check if it's safe to place this digit
                    if(isSafe(board, i, j, c)) {

                        // Place the digit
                        board[i][j] = c;

                        // Recursively try to solve the remaining board
                        bool nextSolution = sudokoSolver(board);

                        // If solution found → keep it
                        if(nextSolution) return true;

                        // Otherwise backtrack (undo the move)
                        board[i][j] = '.';
                    }
                }

                // If no number 1–9 fits here → this path is wrong
                return false;
            }
        }
    }

    // If no empty cells left → solved
    return true;
}


int main() {

    // Sudoku board ('.' means empty cell)
    vector<vector<char>> board{
        {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
        {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
        {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
        {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
        {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
        {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'}
    };

    // Solve the Sudoku puzzle
    sudokoSolver(board);

    // Print the final solved board
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
