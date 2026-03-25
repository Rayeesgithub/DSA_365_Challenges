### 🔥 1. Single Integer Input
Input->10
int n;
cin >> n;
long long x; cin >> x;   // use for large numbers!(always prefer this)
double d;    cin >> d;
char c;      cin >> c;   // skips whitespace automatically

### Always prefer long long over int when the problem says numbers up to 10^9 or more.

✅ Types for Decimal Input
| Type          | Precision                  | Example             |
| ------------- | -------------------------- | ------------------- |
| `float`       | ~6 decimal digits          | 3.14                |
| `double`      | ~15 digits ✅ (recommended) | 3.14159265358979    |
| `long double` | more precision             | very large decimals |



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
