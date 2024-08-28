//striver sheet

//Broute force
#include<bits/stdc++.h>
using namespace std;
int findSingle(vector<int>&arr){
  unordered_map<int,int>mp;
  for(int i=0; i<arr.size(); i++){
    mp[arr[i]]++;
  }
  int result=0;
  for(auto it:mp){
    if(it.second==1){
      result=it.first;
    }
  }
  return result;
}


// Optimal Apprach
int findSingle(vector<int>&arr){
  int ans=0;
  for(int i=0; i<arr.size();i++){
    ans=ans^arr[i];
  }
  return ans;
}
int main(){
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  int ans=findSingle(arr);
  cout<<"The Single Element is:"<<ans;
}
