// love babbar
#include<bits/stdc++.h>
using namespace std;
void  printing(int n,int i){
   if(i>n) return;
   cout<<i<<" ";
   printing(n,i+1);
}
int main(){
    int n;
    cin>>n;
    int i=1;
    printing(n,i);
    return 0;
}
