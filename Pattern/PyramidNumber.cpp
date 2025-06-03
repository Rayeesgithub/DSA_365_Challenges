1 
1 2 
1 2 3 
1 2 3 4 
1 2 3 4 5



  #include<bits/stdc++.h> 
using namespace std;

int main(){
    for(int row=0; row<5; row++){         
        for(int col=0; col<row+1; col++){    
            cout<<col+1<<" ";            
        }
        cout<<endl;                     
    }
}
