//striver sheet

// broute force
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=10;int m=7;
    int arr1[n]={1,2,3,4,5,6,7,8,9,10};
     int arr2[m]={2,3,4,4,5,11,12};
  vector<int>temp;
   for(int i=0; i<n; i++){
    temp.push_back(arr1[i]);
   }
     for(int i=0; i<m; i++){
    temp.push_back(arr2[i]);
   }
   set<int>st;
   for(int i=0; i<temp.size();i++){
    st.insert(temp[i]);
   }
   for(auto it:st){
    cout<<it<<" ";
   }
}
