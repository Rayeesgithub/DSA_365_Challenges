// love Babbar
#include<bits/stdc++.h>
using namespace std;
int fact(int n){
    if(n==0 || n==1) return 1;
    int res=n*fact(n-1);
    return res;
}
int main(){
    int n;
    cin>>n;
    int ans=fact(n);
    cout<<ans<<" ";
    return 0;
}
