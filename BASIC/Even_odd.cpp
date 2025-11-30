
Input: n=5
Output: odd
Explanation: 5 is not divisible by 2.

Time && space=0(1)

  apprach 1
#include<bits/stdc++.h>
using namespace std;
int main(){
int n=29;
if(n%2==0){
  cout<<"even Numver";
}
else{
  cout<<"ODD Number";
}
}


// apprach 2
int main(){
int n=29;
if(n&1){
  cout<<"odd Numver";
}
else{
  cout<<"even Number";
}
}
