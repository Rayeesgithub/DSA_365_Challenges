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
