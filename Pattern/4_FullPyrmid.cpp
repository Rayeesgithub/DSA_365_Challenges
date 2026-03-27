#### 1. Full Pyramid
        * 
      * * * 
    * * * * * 
  * * * * * * *

int main(){
  int n=5;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n-i; j++){  // spaces decrease every row → shifts stars towards center
      cout<<"  ";
    }
      // number of stars = 2*i - 1
    // stars increase in odd numbers: 1, 3, 5, 7...

    for(int k=1; k<=2*i-1;k++){
      cout<<"*"<<" ";
    }
    cout<<endl;
  }
}


#### 2. Inverted Full Pyramid

  * * * * * * * * * 
    * * * * * * * 
      * * * * * 
        * * * 
          *


int main(){
  int n=5;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=i-1; j++){
      cout<<"  "; //  // number of spaces = i
    }

      // number of stars = 2*n - 2*i + 1
    // stars decrease in odd numbers: (2n-1), (2n-3), (2n-5)...
    // this creates inverted full pyramid shape
     
    for(int k=1; k<=2*n-2*i+1;k++){ // 2*(n - i) + 1
      cout<<"*"<<" ";
    }
    cout<<endl;
  }
}
