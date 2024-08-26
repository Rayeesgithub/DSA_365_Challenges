//striver sheet

// Broute force
 //Broute force
//       for(int i=2;i<n; i++){
//           if(n%i ==0){
//               return false; }   }  return true;
//   }int countPrimes(int n) {
//          if(n<2){
//           return false;
//       } int count=0;
//        for(int i=2; i<n; i++){
//            if(checkPrime(i)){
//                count++;} } return count;


// optimal Approach
#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n; int count=0;
  vector<bool>prime(n,true);
  prime[0]=false; prime[1]=true;
  for(int i=2; i<n; i++){
    if(prime[i]){
  count++;
  for(int j=2*i; j<n;j=j+i ){
    prime[j]=false;
  }

    }
  }
  cout<<count;
}
