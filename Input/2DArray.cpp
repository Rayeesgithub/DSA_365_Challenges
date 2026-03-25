🔥 1. Matrix Input

input:   3 3 
    
    →  1 2 3 
    →  4 5 6 
    →  7 8 9

int n, m;
cin >> n >> m;  

int arr[n][m];  OR vector<vector<int>> arr(n, vector<int>(m));
for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
        cin >> arr[i][j];
    }
}


#### 🔴 Matrix of characters (grid puzzle)
Input:   3 3 
    
    →  a b c 
    →  d e f 
    →  g h i

int n, m;
cin >> n >> m;

vector<vector<char>> arr(n, vector<char>(m));
for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
        cin >> arr[i][j];
    }
}





🔥 5) 2D Array Input in String Format

👉 Input: [[1,2,3],[4,5,6],[7,8,9]]

    
#include <bits/stdc++.h>
using namespace std;
int main(){
    string line;
    getline(cin, line);   // "[[1,2,3],[4,5,6],[7,8,9]]"

    // step 1: replace [ ] , all with spaces
    for(char& c : line)
        if(c=='['||c==']'||c==',') c=' ';
    // line = "  1 2 3   4 5 6   7 8 9  "

    // step 2: read all numbers into flat vector
    istringstream ss(line);
    vector<int> flat;
    int num;
    while(ss >> num) flat.push_back(num);
    // flat = {1,2,3,4,5,6,7,8,9}

    // step 3: reshape into 2D (rows x cols known)
    int rows=3, cols=3;
    vector<vector<int>> mat(rows, vector<int>(cols));
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            mat[i][j] = flat[i*cols + j];

    // print to verify
    for(auto& row : mat){
        for(int x : row) cout << x << " ";
        cout << "\n";
    }
}
