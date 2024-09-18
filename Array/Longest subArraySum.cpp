// striver sheet
// gfg ->Longest Sub-Array with Sum K
int lenOfLongSubarr(int A[],  int N, int K) 
    { 
       // using 3 loop Time Complexity: O(N^3)
       int len=0;
    //   for(int i=0; i<N; i++){
    //       for(int  j=i; j<N; j++){
    //           long long int sum=0;
    //           for(int k=i; k<=j; k++){
    //               sum=sum+A[k];
    //           }
    //           if(sum==K){
    //             len=max(len,j-i+1);   
    //           }
    //       }
    //       return len;
    //   }
    
    
    // using twqo loops Time Complexity: O(N^2)
    
    //   for(int i=0; i<N; i++){
    //       long long sum=0;
    //       for(int j=i; j<N; j++){
    //           sum=sum+A[j];
    //           if(sum==K){
    //              len=max(len,j-i+1);
    //           }
    //       }
          
    //   }
    //   return len;
    

// two Pointer
#include<bits/stdc++.h>
using namespace std;
int subArr(int arr[],int n,int k){
    int len=0; 
   int left=0;int right=0;
   int sum=arr[0];
   while(right<n){
    while(left<=right && sum>k){
        sum-=arr[left];
        left++;
    }
    if(sum==k){
        len=max(len,right-left+1);
    }
   
   right++;
   if(right<n){
    sum+=arr[right];
   }
   }
   return len;
}
int main(){
    int n=6;
    int arr[n]={10, 5, 2, 7, 1, 9};
    int k=15;
    int ans=subArr(arr,n,k);
    cout<<"Longest Subbaray:"<<ans;
    return 0;
}
