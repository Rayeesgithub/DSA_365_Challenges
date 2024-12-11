#include<bits/stdc++.h>
using namespace std;
int findMinCoins(vector<int>&coins,int amount){
    if(amount==0) return 0;
    if(amount<0) return INT_MAX;
    int mini=INT_MAX;
    
    for(int i=0; i<coins.size();i++){
         int ans=findMinCoins(coins,amount-coins[i]);
     if(ans!=INT_MAX){
       mini=min(mini,1+ans);
     }
    }
    return mini;
}
int memo(vector<int>&coins,int amount,vector<int>&dp){
     if(amount==0) return 0;
    if(amount<0) return INT_MAX;
    int mini=INT_MAX;
    //step-2
    if(dp[amount]!=-1)
    return dp[amount];
    
    for(int i=0; i<coins.size();i++){
         int ans=memo(coins,amount-coins[i],dp);
     if(ans!=INT_MAX){
       mini=min(mini,1+ans);
     }
     
    }
    dp[amount]=mini;
    return mini;
}
int tabulization(vector<int>&coins,int amount){
    vector<int>dp(amount+1,INT_MAX);
    dp[0]=0;
    for(int i=1; i<=amount; i++){
         for(int j=0; j<coins.size();j++){

         if(i-coins[j]>=0 && dp[i-coins[j]!=INT_MAX]){
                int ans = dp[i-coins[j]];
                dp[i] = min(dp[i],1+ans);
            }
     
    }
  
   
    } return dp[amount];
}
int main(){
    vector<int>coins={1,2,5};
    int amount=11;
    // int ans=findMinCoins(coins,amount);
    // vector<int>dp(amount+1,-1);
    // int ans=memo(coins,amount,dp);
    int ans=tabulization(coins,amount);
    if(ans==INT_MAX) return -1;
    cout<<"Minimum Number of coins is:"<<ans;

}
