
#include <bits/stdc++.h>
using namespace std;
int  secondOcc(vector<int>&arr,int n,int target){
    int s=0; int e=n-1; int ans=-1;
    while(s<=e){
        int mid=(s+e)/2;

    if(arr[mid]==target){
        ans=mid;
       s=mid+1;
    }
    else if(arr[mid]<target){
        s=mid+1;
    }
    else{
        e=mid-1;
            }
    }
    return ans;
}
int  firstOcc(vector<int>&arr,int n,int target){
    int s=0; int e=n-1; int ans=-1;
    while(s<=e){
        int mid=(s+e)/2;

    if(arr[mid]==target){
        ans=mid;
        e=mid-1;
    }
    else if(arr[mid]<target){
        s=mid+1;
    }
    else{
        e=mid-1;
            }
    }
    return ans;
}
pair<int,int>first_last(vector<int>&arr,int n,int target){
    int first=firstOcc(arr,n,target);
    int second=secondOcc(arr,n,target);
    return {first,second};
}
int count(vector<int>&arr,int n,int target){
    pair<int,int>ans=first_last(arr,n,target);
  return (ans.second-ans.first+1);
}
int main()
{
    int n=8;
    vector<int>arr={1, 1, 2, 2, 2, 2, 2, 3};
     int target=2;
    int ans=count(arr,n,target);
    cout<<endl;
    cout<<"maximum Occurence is:"<<ans<<" ";
    return 0;
}


