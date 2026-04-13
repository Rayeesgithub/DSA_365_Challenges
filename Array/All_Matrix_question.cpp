### 1.🟥 Transpose of Matrix
Input: mat[][] = [[1, 1, 1, 1],
                [2, 2, 2, 2],
                [3, 3, 3, 3],
                [4, 4, 4, 4]]

    Output: [[1, 2, 3, 4],
       [1, 2, 3, 4],
       [1, 2, 3, 4],
       [1, 2, 3, 4]]

- code
    for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        swap(mat[i][j], mat[j][i]);
    }
}


  
### 2. 🟥 Rotate Image by 90 degree in clockwise

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
for(int i=0; i<n; i++){
    reverse(arr[i].begin(), arr[i].end());
}
🔷 Dry Run
Row 0:
[1,4,7] → [7,4,1]
Row 1:
[2,5,8] → [8,5,2]
Row 2:
[3,6,9] → [9,6,3]
🔷 Final Matrix
7 4 1
8 5 2
9 6 3


### 3. 🟥 Rotate a matrix by 90 degrees in an anticlockwise direction
🔷 Input
[
 [1,2,3],
 [4,5,6],
 [7,8,9]
]

🔷 Final Output
[
 [3,6,9],
 [2,5,8],
 [1,4,7]
]

int main(){
    int n; int m;
    int arr[n][m]={[1, 2, 3], [4, 5, 6], [7, 8, 9]}

    // Step 1: Transpose
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            swap(arr[i][j],arr[j][i]);
        }
    }

    // Step 2: Reverse Columns
    for(int j=0; j<m; j++){
      int top=0; int bottom=n-1;
      while(top<bottom){
         swap(arr[top][j],arr[bottom][j]);
         top++;  bottom--;
      }
    }
     for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
           cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
  
}


### 4. 🟥 Reverse each row of matrix

Input: arr[][] = 
{ {1, 2, 3},
  {4, 5, 6},
  {7, 8, 9} }
Output:
3 2 1
6 5 4
9 8 7

  
    // row reverse 

    for(int i=0; i<n; i++){
       reverse(arr[i].begin(),arr[i].end());
       
    }
  
  
     for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
           cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }


### 5. 🟥 reverse  each columns
Input: arr[][] =  {{3, 2, 1}
                          {4, 5, 6},
                          {9, 8, 7}}
     Output:  9 8 7
              4 5 6
              3 2 1

           
    // column reverse

    for(int i=0; i<m; i++){
        int top=0; int bottom=n-1;
       while(top<bottom){
         swap(arr[top][i],arr[bottom][i]);
        top++; bottom--;
       }
    }

    
  
     for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
           cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
  
