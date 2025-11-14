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
