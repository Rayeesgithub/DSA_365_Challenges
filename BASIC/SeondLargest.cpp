#include<iostream>
using namespace std;

int main(){
    int a, b,c;
    cout<<"enter the number";
    cin>>a; cin>>b; cin>>c;
    // int largest=findLargest(a,b,c);
    // int largest=max(a,max(b,c));
    // int ans=0;
    // if(largest>a && (a>b || a>c)){
    //     ans=a;
    // }
    // else if(largest>b && (b>c || b>a)){
    //     ans=b;
    // }
    // else{
    //     ans=c;
    // }

    // 2nd Apprach
    int ans=0;
    if((a>b && a<c) || (a<b && a>c)){
      ans=a;
    }
    else if((b>a && b<c) || (b<a && b>c)){
        ans=b;
    }
    else{
        ans=c;
    }
    cout<<"Second Largest Number is:"<<ans;
}
