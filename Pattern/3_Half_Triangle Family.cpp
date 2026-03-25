#### 1. 
Left triangle
j <= i

*
* *
* * *
* * * *
* * * * *

#include<bits/stdc++.h>   
using namespace std;      

int main(){

  int n;
  cin >> n;   // taking input (number of rows for pattern)

  // Outer loop -> controls number of rows
   for(int i = 1; i <= n; i++){

    // Inner loop -> prints stars in each row
    // number of stars = current row number (i)
    for(int j = 1; j <= i; j++){
      cout << "*" << " ";   // print star with space
    }

    cout << endl;  // move to next line after each row
  }
}



#### 2.
  Inverted left
j <= n-i+1
* * * * *
* * * *
* * *
* *
*

int main(){
  int n;
  cin>>n;
  for(int i=1; i<=n; i++){
    
    // n - i + 1 → stars decrease every row
    for(int j=1; j<=n-i+1; j++){ 
      cout<<"*"<<" ";
    }
    cout<<endl;
  }
}

  
