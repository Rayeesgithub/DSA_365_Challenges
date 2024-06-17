#include<iostream>
using namespace std;
bool checkprime(int n){
if (n < 2) {
        return false;
    }
  for(int i=2; i<n; i++){
    if(n%i==0){
      return false;
    }
   
     
  }
  return true;
}
void printPrime(int n){
  for(int i=2; i<=n; i++){
   if( checkprime(i)){
    cout<<i<<" ";
   }
  }
}

int main(){
  int n;
  cout<<"enter the Number:"<<endl;
  cin>>n;
  checkprime(n);
  printPrime(n);
}
