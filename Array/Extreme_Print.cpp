// love Babbar
#include<iostream>
#include<vector>
using namespace std;
 
  void findextreme(vector<int>arr,int n){
  int i=0; int j=n-1;
  while(i<j){
   
    cout<<arr[i]<<" "<<arr[j]<<" ";
    
     i++; j--;
  }
  if(i==j){
      cout<<arr[i];
    }
  }
int main(){
    vector<int>arr ={1,2,3,4,5};
    int n=arr.size();
    findextreme(arr,n);
   return 0;
}
