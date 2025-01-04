#include<bits/stdc++.h>
using namespace std;
int main(){
 int n;
 cout<<"enter any Number:";
 cin>>n;
 vector<int>ans;
 while(n!=0){
    int digit=n%2;
    ans.push_back(digit);
    n=n/2;
 }
 reverse(ans.begin(),ans.end());
 for(int i=0; i<ans.size();i++){
    cout<<ans[i]<<" ";
 }
}

//2nd approach
// void toBinary(int N)
// {
//        int i=0;
//        int ans=0;
//        while(N!=0){
//           int rem=N%2;
//           ans=ans+(rem * pow(10, i));;
        
//           i++;  N=N/2;
          
//        }
//        std::cout<<ans;       
       
// }
