https://leetcode.com/problems/rotate-image/
Input: [[1,2,3],[4,5,6],[7,8,9]]

Output: [[7,4,1],[8,5,2],[9,6,3]]
    
🔁 DRY RUN (step-by-step)
    ➤ Iteration 1: i = 0
   Row = 1 2 3
    j = 0 , rotated[0][3-1-0] = rotated[0][2] = arr[0][0] = 1,
    j = 1,  rotated[1][2] = arr[0][1] = 2,
    j = 2 , rotated[2][2] = arr[0][2] = 3,
    0 0 1
    0 0 2
    0 0 3
so on .....
// broute force
    //Time Complexity: O(N²)  Space Complexity: O(N²
#include<bits/stdc++.h>
using namespace std;
void rotatNinty(vector<vector<int>>&arr,int n,int m){
    vector<vector<int>>rotated(n,vector<int>(n,0));
     for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      rotated[j][n-1-i]=arr[i][j];
    }
   }
    arr = rotated;
}
int main(){
    int n,m;
    cout<<"enter the row:"<<endl;
    cin>>n;
    cout<<"enter the col:"<<endl;
    cin>>m;
    vector<vector<int>>matrix(n,vector<int>(m));
   for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
        cin>>matrix[i][j];
    }
   }
    rotatNinty(matrix,n,m);
   cout<<"90 degree Rotate"<<endl;
    for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
       cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
   }
}





// approach2   Time Complexity: O(N²) && space=(1)
#include<bits/stdc++.h>
using namespace std;
  
int main(){
  
  // Creating a 2D vector (matrix)
  vector<vector<int>> arr = {{1,2,3},{4,5,6},{7,8,9}};
  
  int n = arr.size();       // number of rows
  int m = arr[0].size();    // number of columns

  // -------------------------------
  // STEP 1: TRANSPOSE THE MATRIX
  // -------------------------------
  // Swap elements across the diagonal
  for(int i = 0; i < n; i++){
    for(int j = i + 1; j < m; j++){
      
      // swap element at (i, j) with element at (j, i)
      swap(arr[i][j], arr[j][i]);
    }
  }

  // -------------------------------
  // STEP 2: REVERSE EACH ROW
  // -------------------------------
  // After reversing rows, matrix becomes rotated by 90° clockwise
  for(int i = 0; i < n; i++){
    reverse(arr[i].begin(), arr[i].end());
  }

  // -------------------------------
  // STEP 3: PRINT FINAL MATRIX
  // -------------------------------
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}



Dry run->
Original Matrix
1 2 3
4 5 6
7 8 9
after Transpose
1 4 7
2 5 8
3 6 9
After Reversing Each Row
7 4 1
8 5 2
9 6 3
