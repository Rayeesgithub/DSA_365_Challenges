// striver sheet
//Broute force

#include<bits/stdc++.h>
using namespace std;
vector<int>solve(vector<int>&arr){
   int n=arr.size();
   sort(arr.begin(),arr.end());
   int num=n;
   vector<int>ans(2);
   unordered_map<int,int>mp;
for(int i=0; i<n; i++){
    mp[arr[i]]++;
   }
   for(auto it:mp){
    if(it.second==2){
        ans[0]=(it.first);
    }
  }
   for(int i=1; i<=n; i++){
    if(mp.find(i)==mp.end()){
     ans[1]=(i);
    }
   }
   return ans;
}




int main(){
vector<int>arr={3,1,2,5,3};
cout<<"finding and repeating Element is:"<<endl;
 vector<int>ans=solve(arr);
 
 for(int i=0; i<ans.size(); i++){
  cout<<ans[i]<<" ";
 }
}
