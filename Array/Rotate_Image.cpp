https://leetcode.com/problems/rotate-image/

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
