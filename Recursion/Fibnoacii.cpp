// love babbar

#include<bits/stdc++.h>
using namespace std;
  void printFib(int n){
    int a=0; int b=1; int c;
    if(n==0){
        cout<<a<<" ";
        return;
    }
    cout<<a<<" "<<b<<" ";

    for(int i=2; i<=n;i++){
        c=a+b;
        cout<<c<<" ";
        a=b;
        b=c;
    }
  }
int main(){
    int n;

    cin>>n;
   printFib(n);
   return 0;
}
