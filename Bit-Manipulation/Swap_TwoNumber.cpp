//striver sheet

// Approach-> using temporary variable
#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  cout<<"Enter Two Number:"<<endl;
  cin>>a; cin>>b;
  cout<<"Before Swapping:"<<a<<" "<<b; cout<<endl;
  int temp=a;
  a=b;
  b=temp;
  cout<<"After Swapping:"<<a<<" "<<b;
  return 0;
}
