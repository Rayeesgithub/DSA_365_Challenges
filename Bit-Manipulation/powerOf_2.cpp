// striver sheet


//broute force
#include<bits/stdc++.h>
using namespace std;
bool checkPowerTwo(int n){
  for(int i=0; i<n; i++){
    if(pow(2,i)==n){
      return true;
    }
  }
  return false;
}
int main(){
  int n;
  cin>>n;
  if(checkPowerTwo(n)){
    cout<<"'Yes' this is Power of Two"<<endl;
  }
  else{
    cout<<"'No' this is not Power of Two"<<endl;
  }
}

//optimal apprach
#include<bits/stdc++.h>
using namespace std;
bool checkPowerTwo(int n){
  if(n==0) return false;
 
  while(n>0){
     if(n==1)  return true;
    if(n%2!=0){
      break;
    }
    n=n/2;
  }
  return false;
}
int main(){
  int n;
  cin>>n;
  if(checkPowerTwo(n)){
    cout<<"'Yes' this is Power of Two"<<endl;
  }
  else{
    cout<<"'No' this is not Power of Two"<<endl;
  }
}
