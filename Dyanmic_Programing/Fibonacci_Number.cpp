#include<bits/stdc++.h>
using namespace std;
int solveusingRecursion(int n){
    if(n==0 || n==1){
        return n;
    }
    int ans=solveusingRecursion(n-1)+solveusingRecursion(n-2);
    return ans;
}
int memoization(int n, vector<int>&dp){
    if(n==0 || n==1) return n;
    //step-2
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]=memoization(n-1,dp)+memoization(n-2,dp);
    return dp[n];
}
int tabulization(int n){
    vector<int>dp(n+1,-1);
    dp[0]=0;
    if(n == 0){
            return dp[0];
        }
    dp[1]=1;
    if(n == 1){
            return dp[1];
        }
        for(int i=1; i<=n; i++){
      dp[i]=tabulization(n-1)+tabulization(n-2);
        }
        return dp[n];
}
int spaceOpt(int n){
  int prev2=0;
  int prev1=1;
  int curr=0;
    if(n == 0)
            return prev2;
        if(n == 1)
            return prev1;
            
        for(int i=2; i<=n; i++){
           curr=prev1+prev2;
           prev2=prev1;
           prev1=curr;
        }
        return curr;
}
int main(){
    int n;
    cout<<"enter the Number:";
    cin>>n;
    // int ans=solveusingRecursion(n);
    // vector<int>dp(n+1,-1);
    // int ans=tabulization(n);
    int ans=spaceOpt(n);
    cout<<ans<<" ";
    return 0;
}
