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

// approach2-> without using temporary variable
#include <iostream>
using namespace std;

int main() {
    int a, b;

    // Input two numbers
    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "Before swapping: a = " << a << ", b = " << b << endl;

  a=a+b;
  b=a-b;
  a=a-b;
cout<<" after swapping: a= "<<a<<" , b= "<<b<<endl;
    return 0;
}

