#include<iostream>
using namespace std;
int main(){
    int size=5;
    int arr[5]={3,4,5};

  
    int ans=0;
    for(int i=0; i<3; i++){
     ans=ans*10+arr[i];
    }
   cout<<"Digit to number is:"<<ans;
}
