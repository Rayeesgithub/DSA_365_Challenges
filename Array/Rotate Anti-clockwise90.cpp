Input:   {{1,2,3},
          {4,5,6},
          {7,8,9}}
Output:
        3 6 9 
        2 5 8 
        1 4 7 


  void rotateAntiClockwise(vector<vector<int>>& arr) {
    int n = arr.size();
    vector<vector<int>> rotated(n, vector<int>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            rotated[n-1-j][i] = arr[i][j];
        }
    }

    arr = rotated;
}
