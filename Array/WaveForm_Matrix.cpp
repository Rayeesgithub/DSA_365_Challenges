#include<bits/stdc++.h>
using namespace std;
int main(){
    int row,col;
    cout<<"enter the row:";
    cin>>row;
    cout<<endl;
    cout<<"enter the column:";
    cin>>col;
    int arr[row][col];
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>>arr[i][j];
        }
    }
   cout<<"waveform Print"<<endl;
   for(int j=0; j<col; j++){
    if(j%2==0){
        for(int i=0; i<row; i++){
            cout<<arr[i][j]<<" ";
        }
    }
    else{
        for(int i=row-1; i>=0; i--){
            cout<<arr[i][j]<<" ";
        }
    }
   }
}
