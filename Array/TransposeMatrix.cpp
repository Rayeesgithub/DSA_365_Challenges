#include<bits/stdc++.h>
using namespace std;

int main(){
      int n,m;
    cout<<"enter the number of row:"<<endl;
    cin>>n;
    cout<<"enter the number of coimnL"<<endl;
    cin>>m;

    vector<vector<int>>matrix(n,vector<int>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>matrix[i][j];
        }
    }

  
cout<<"Transpose of matrix"<<endl;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<matrix[j][i]<<" ";
        }
        cout<<endl;
    }
    
}
