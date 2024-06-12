#include<iostream>
using namespace std;
bool checkPrime(int n){
   if(n<2) return false;
   for(int i=2; i<=n;i++){
    if(n%i==0) return false;
    break; // here you mistake
   }
   return true;
}
int main(){
    int n; cout<<"enter the numer:"<<endl;
    cin>>n;
    if(checkPrime(n)){
        cout<<"This is prime Number"<<endl;
    }
    else{
        cout<<"this is not Prime Not Number";
    }
}
// Approach-2 optimal
bool checkPrime(int n){
   if(n<2) return false;
    for(int i = 1; i <= sqrt(n); i++){
    if(n%i==0) return false;
     // here you mistake
   }
   return true;
}
