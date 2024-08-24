// striver sheet
#include<bits/stdc++.h>
using namespace std;
void findSum(int arr[],vector<int>&output,int target,int i,vector<vector<int>>&ans,int n){
  if(i==n){
    if(target==0){
      ans.push_back(output);
    
    }
    return;
  }
  if(arr[i]<=target){
    output.push_back(arr[i]);
    findSum(arr,output,target-arr[i],i,ans,n);
    output.pop_back();
  }
  findSum(arr,output,target,i+1,ans,n);
}
int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
 vector<int>output;
 vector<vector<int>>ans;
 int target=8;
 findSum(arr,output,target,0,ans, n);
  cout << "Combinations are: " << endl;
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++)
      cout << ans[i][j] << " ";
    cout << endl;
}
}
