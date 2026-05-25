Input: -12, 11, -13, -5, 6, -7, 5, -3, -6
Output: -12 -13 -5 -7 -3 -6 11 6 5


#include<bits/stdc++.h>

using namespace std;

int main(){
vector<int>arr={2,0,-1,6,-4,7,-5};

int i=0; int j=arr.size()-1;

while(i<j){
   if(arr[i]<0){
      i++;
   }
   else if(arr[j]>0){
      j--;
   }
   else{
      swap(arr[i],arr[j]);
      i++; j--;
   }
}

for(auto it:arr){
   cout<<it<<" ";
}
  
}
