### 🔥 1. Single Integer Input
Input->10
int n;
cin >> n;

<img width="623" height="262" alt="image" src="https://github.com/user-attachments/assets/7f95d50e-2636-4c51-bb2e-280faea02256" />


Example
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
 
  // check even/odd
  if(n%2==0){
    cout<<"this is even Number";
  }
  else{
    cout<<"this is odd Number";
  }
  return 0;
}


### 🔥 2. Multiple Integers 
👉 Input: 10 20 30
int a, b, c;
cin >> a >> b >> c; 
ye both input ke eligible hai
case1-> if input in same line like(10 30 5)
case2->   input in new line like (10 in first line, 20 in seocnd line ,30 in 3rd line)

-> cin >> automatically skips spaces and newlines — no need to manually split.
C++ ka cin whitespace (space, tab, newline) ko separator ki tarah treat karta hai. Isliye aapko alag se handle karne ki zaroorat nahi jab tak beech mein comma ( , ) na ho.

Example-> 
  int main(){
  int a,b,c;
  cin>>a>>b>>c;
 
  // check even/odd
  if(a>b && a>c){
    cout<<"a is largest number";
  }
  else if(b>a && b>c){
    cout<<"b is largest Number";
  }
  else{
    cout<<"c is largest Number";
  }
}
