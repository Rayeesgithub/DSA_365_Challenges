https://www.geeksforgeeks.org/problems/count-the-zeros2550/1
// love babbar

#include<iostream>
#include<vector>
using namespace std;
  void FindCount(vector<int>&arr,int n){
    int count0=0; int count1=0;
    for(int i=0; i<n; i++){
        if(arr[i]==0){
            count0++;
        }
        else if(arr[i]==1){
            count1++;
        }
    }
    cout<<"Number Zero count"<<count0<<endl;
    cout<<"Number of one count"<<count1<<endl;

  }
int main(){
    vector<int>arr ={1,0,0,0,1,0,1};
    int n=arr.size();
    FindCount(arr,n);
   
}
