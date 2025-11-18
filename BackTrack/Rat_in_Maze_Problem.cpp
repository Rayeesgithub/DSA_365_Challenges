Input: maze[][] = [[1, 0, 0, 0], [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1]]
Output: ["DDRDRR", "DRDDRR"]
Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.




#include<bits/stdc++.h>
using namespace std;

// ---------------- SAFETY CHECK FUNCTION -----------------
bool isSafe(int maze[4][4], int x, int y, int row, int col, vector<vector<bool>>& visited) {
    
    // A position is safe if:
    // 1. x and y are inside the boundary
    // 2. maze[x][y] == 1 (means path is open, not blocked)
    // 3. visited[x][y] == false (not visited before)
    if ((x >= 0 && x < row) && (y >= 0 && y < col) && 
        (maze[x][y] == 1) && (visited[x][y] == false)) {
        return true;
    }
    return false;
}


// ---------------- RECURSIVE BACKTRACKING FUNCTION -----------------
void solveMaze(int maze[4][4], int row, int col, int i, int j,
               vector<vector<bool>>& visited, vector<string>& path, string output) {
    
    // BASE CASE:
    // If we reach the destination (bottom-right corner)
    if (i == row - 1 && j == col - 1) {
        path.push_back(output); // store the found path
        return;
    }
  
    // ---------- MOVE DOWN (D) ----------
    if (isSafe(maze, i + 1, j, row, col, visited)) {
        visited[i + 1][j] = true;                    // mark visited
        solveMaze(maze, row, col, i + 1, j, visited, path, output + 'D'); // go down
        visited[i + 1][j] = false;                   // backtrack
    }
  
    // ---------- MOVE LEFT (L) ----------
    if (isSafe(maze, i, j - 1, row, col, visited)) {
        visited[i][j - 1] = true;
        solveMaze(maze, row, col, i, j - 1, visited, path, output + 'L');
        visited[i][j - 1] = false;
    }
    
    // ---------- MOVE RIGHT (R) ----------
    if (isSafe(maze, i, j + 1, row, col, visited)) {
        visited[i][j + 1] = true;
        solveMaze(maze, row, col, i, j + 1, visited, path, output + 'R');
        visited[i][j + 1] = false;
    }
  
    // ---------- MOVE UP (U) ----------
    if (isSafe(maze, i - 1, j, row, col, visited)) {
        visited[i - 1][j] = true;
        solveMaze(maze, row, col, i - 1, j, visited, path, output + 'U');
        visited[i - 1][j] = false;
    }
}

int main() {

    // MAZE INPUT (1 = open path, 0 = blocked)
    int maze[4][4] = {
        {1, 0, 0, 0}, 
        {1, 1, 0, 1}, 
        {1, 1, 0, 0}, 
        {0, 1, 1, 1}
    };
    
    int row = 4;
    int col = 4;
    
    // If starting point (0,0) is blocked → No path exists.
    if (maze[0][0] == 0) {
        cout << "No Path Exists";
        return 0;
    }
  
    // visited matrix to track visited cells
    vector<vector<bool>> visited(row, vector<bool>(col, false));
  
    vector<string> path;   // to store all possible paths
    string output = "";    // stores one path
  
    visited[0][0] = true;   // mark starting point as visited

    // Start exploring from (0,0)
    solveMaze(maze, row, col, 0, 0, visited, path, output);
  
    // Print all found paths
    for (auto it : path) {
        cout << it << " ";
    }
}
