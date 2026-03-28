#### 1. Half Diamond Problem

* 
* * 
* * * 
* * * * 
* * * * *
* * * *
* * *
* *
*

// 1st approach
    
int main(){
  int n=5;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=i; j++){
      cout<<"*"<<" ";
    }
    cout<<endl;
  }
   for(int i=1; i<=n; i++){
    for(int j=1; j<=n-i; j++){
      cout<<"*"<<" ";
    }
    cout<<endl;
  }
}

// 2nd approach
int main() {
    int n = 4;

    // Upper part
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }

    // Lower part
    for(int i = n - 1; i >= 1; i--) {
        for(int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}



### Full Diamond Shape

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    #include <iostream>
using namespace std;

int main() {
    int n= 5;

   

    for (int row = 0; row< n; row++) {
       for(int col=0; col<row+1;col++){
        cout<<"*"<<" ";
       }
cout<<endl;
      
    }
    for (int row = 0; row< n; row++) {
       for(int col=0; col<n-row-1;col++){
        cout<<"*"<<" ";
       }

      cout<<endl;
    }


      
   
    return 0;
}
