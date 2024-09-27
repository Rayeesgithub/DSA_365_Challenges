#include<bits/stdc++.h>
using namespace std;

// Function to check if the current position is safe to move
bool isSafe(int maze[4][4], int x, int y, int row, int col, vector<vector<bool>>& visited) {
    // Check if x and y are within bounds of the maze, 
    // maze[x][y] is 1 (open path), and the cell is not yet visited.
    if ((x >= 0 && x < row) && (y >= 0 && y < col) && (maze[x][y] == 1) && (visited[x][y] == false)) {
        return true;
    }
    return false;
}

// Function to solve the maze using backtracking
void solveMaze(int maze[4][4], int row, int col, int i, int j, vector<vector<bool>>& visited, vector<string>& path, string output) {
    // Base case: If we've reached the bottom-right corner, add the path to the result.
    if (i == row - 1 && j == col - 1) {
        path.push_back(output);
        return;
    }
  
    // Move down
    if (isSafe(maze, i + 1, j, row, col, visited)) {
        visited[i + 1][j] = true;  // Mark the cell as visited
        solveMaze(maze, row, col, i + 1, j, visited, path, output + 'D');  // Add 'D' to output path
        visited[i + 1][j] = false;  // Unmark the cell for backtracking
    }
  
    // Move left
    if (isSafe(maze, i, j - 1, row, col, visited)) {
        visited[i][j - 1] = true;
        solveMaze(maze, row, col, i, j - 1, visited, path, output + 'L');
        visited[i][j - 1] = false;
    }
    
    // Move right
    if (isSafe(maze, i, j + 1, row, col, visited)) {
        visited[i][j + 1] = true;
        solveMaze(maze, row, col, i, j + 1, visited, path, output + 'R');
        visited[i][j + 1] = false;
    }
  
    // Move up
    if (isSafe(maze, i - 1, j, row, col, visited)) {
        visited[i - 1][j] = true;
        solveMaze(maze, row, col, i - 1, j, visited, path, output + 'U');
        visited[i - 1][j] = false;
    }
}

int main() {
    // Input maze
    int maze[4][4] = {{1, 0, 0, 0}, 
                      {1, 1, 0, 1}, 
                      {1, 1, 0, 0}, 
                      {0, 1, 1, 1}};
    
    int row = 4;  // Correct initialization of row size
    int col = 4;  // Correct initialization of col size
    
    // Check if the starting point is blocked
    if (maze[0][0] == 0) {
        cout << "No Path Exists";
        return 0;
    }
  
    // Create a visited matrix initialized with false
    vector<vector<bool>> visited(row, vector<bool>(col, false));
  
    // To store all possible paths
    vector<string> path;
    string output = "";
  
    // Start solving the maze from (0,0)
    visited[0][0] = true;
    solveMaze(maze, row, col, 0, 0, visited, path, output);
  
    // Print all paths found
    for (auto it : path) {
        cout << it << " ";
    }
}
