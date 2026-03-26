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




#### 3 Number Pattern

1
1 2
1 2 3
1 2 3 4

  int main(){
  int n;
  cin >> n;  
  
  for(int i = 1; i <= n; i++){

    // Inner loop → prints numbers from 1 to current row number (i)
    // So in each row, numbers start from 1 and go till i
    for(int j = 1; j <= i; j++){
      cout << j << " ";  
    }
    cout << endl;
  }
}


#### 4. Same Row Number

1
2 2
3 3 3
4 4 4 4

int main(){
  int n;
  cin>>n;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=i; j++){  // So same number (row number) repeats i times in that row
      cout<<i<<" ";
    }
    cout<<endl;
  }
}


#### 5.  Mirrored Right-Angled Triangle

      *
    * *
  * * *
* * * *

  int main(){
  int n=5;
  for(int i=1; i<=n; i++){
     // n - i spaces
    for(int j=1; j<=n-i; j++){
      cout<<"  "; // two spaces for proper alignment
    }

    for(int k=1; k<=i;k++){  // number of stars = current row number (i)
      cout<<"* ";
    }
    cout<<endl;
  }
}


### 6. Reversed Mirrored Right Triangle

* * * *
  * * *
    * *
      *


  int main(){
  int n=5;
  for(int i=1; i<=n; i++){

    // spaces increase every row → shifts pattern to the right
    for(int j=1; j<=i-1; j++){
      cout<<"  ";
    }

     // stars decrease every row
    for(int k=1; k<=n-i+1;k++){
      cout<<"* ";
    }
    cout<<endl;
  }
}
