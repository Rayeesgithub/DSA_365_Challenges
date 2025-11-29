Input: N = 5, arr[] = {5,4,3,2,1}
Output: {1,2,3,4,5}
Explanation: Since the order of elements gets reversed the first element will occupy the fifth position, the second element occupies the fourth position and so on.

// apprach1 Time=0(n) space=(1)
#include<iostream>
using namespace std;
by looping method
void reverseArray(int arr[],int n){
  for(int i=n-1;i>=0;i--){
    cout<<arr[i]<<" ";
  }
  


// by two pointer
Time=0(n) space=(1)
  void reverseArray(int arr[],int n){
    int i=0; int j=n-1;
    while(i<=j){
        swap(arr[i],arr[j]);
      
        i++; j--;
    }
  }

int main(){
    int arr[5]={1,2,3,4,5};
    int n=5;
    reverseArray(arr,n);
    for(int i=0;i<=n-1;i++){
        cout<<arr[i]<<" ";
    }
}
