

//approach1->Borute force
void Merg(vector<int>&arr1,vector<int>&arr2){
     int n1=arr1.size(); int n2=arr2.size();
     vector<int>ans;
     for(int i=0; i<n1; i++){
        ans.push_back(arr1[i]);

     }
     for(int i=0; i<n2; i++){
        ans.push_back(arr2[i]);
     }

     sort(ans.begin(),ans.end());
     for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
     }
  }

// approach2-> Optimal Approach
#include<bits/stdc++.h>
using namespace std;
void Merge(vector<int>&arr1,int n,vector<int>&arr2,int m){

    int left=n-1;
    int right=0;

    while(left>0 && right<m){
        if(arr1[left]>arr2[right]){
            swap(arr1[left],arr2[right]);
             left++; right--;
        }
        else{
            break;
        }
       
    }
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
}
int main(){
    vector<int>arr1={1,4,8,2};
    vector<int>arr2={2,3,9};

    int n=arr1.size();
    int m=arr2.size();

    Merge(arr1,n,arr2,m);

    cout<<"after mergin two sorted array:";

    for(int i=0; i<n; i++){
        cout<<arr1[i]<<" ";
    }

    cout<<endl;
    for(int i=0; i<m; i++){
        cout<<arr2[i]<<" ";
    }
    return 0;
}
