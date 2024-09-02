//striver sheet NQT


//1st approach
#include<bits/stdc++.h>
using namespace std;
int main() {
   int n=8;
   int arr[n]={2,3,1,9,3,1,3,9};
  //  sort(arr,arr+n);
  //  set<int>st;
  //  for(int i=0; i<n; i++){
  //   st.insert(arr[i]);
  //  }
  //  for(auto it:st){
  //   cout<<it<<" ";
  //  }
  unordered_map<int,int>mp;
  for(int i=0;i<n; i++){
    if(mp.find(arr[i])==mp.end()){
      cout<<arr[i]<<" ";
      mp[arr[i]]++;
    }
  }
}
