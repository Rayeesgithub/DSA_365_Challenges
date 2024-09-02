// TCS NQT Striver
#include<bits/stdc++.h>
using namespace std;



int main() {
   int n=6;
   int arr[n]={8,7,1,6,5,9};
   int mid=n/2;
   vector<int>ans;
   sort(arr,arr+n);
   for(int i=0; i<mid; i++){
    ans.push_back(arr[i]);
   }
   for(int i=n-1; i>=mid; i--){
    ans.push_back(arr[i]);
   }
   for(int i=0; i<ans.size(); i++){
    cout<<ans[i]<<" ";
   }
}
