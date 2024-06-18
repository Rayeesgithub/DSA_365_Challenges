#include<iostream>
using namespace std;
bool LinearSearch(int arr[],int target,int size){
for(int i=0; i<=size-1; i++){
    if(arr[i]==target){
        return true;
    }
    }
return false;
}
int main(){
 int arr[]={4,5,8,12,34,67,38,67,89};
 int size=sizeof(arr)/sizeof(int);
 int target;
 cout<<"enter the your target element"<<endl;
cin>>target;
bool ans= LinearSearch(arr,target ,size);
 if(ans){
    cout<<"Found the target Element"<<endl;
 }
 else{
    cout<<"Not Found Target Element is"<<endl;
 }
return 0;
}
