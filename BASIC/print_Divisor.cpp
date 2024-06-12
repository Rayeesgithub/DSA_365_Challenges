#include<iostream>
using namespace std;
void Divisor(int n){
    for(int i=1;i<=n;i++){
        if(n%i==0){
            cout<<i<<" ";
        }
    }
}
int main(){
    int N=36;
    Divisor(N);
}
