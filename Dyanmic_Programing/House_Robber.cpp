#include<bits/stdc++.h>
using namespace std;
int maxRob(vector<int>&nums,int n){
  if(n==0) return nums[0];
  if(n<0) return 0;

  int include=nums[n]+maxRob(nums,n-2);
  int exculde=0+maxRob(nums,n-1);
  return max(include,exculde);
}
int memo(vector<int>&nums,int n,vector<int>&dp){
    if(n==0) return nums[0];
  if(n<0) return 0;
   if(dp[n]!=-1) return dp[n];
  int include=nums[n]+memo(nums,n-2,dp);
  int exculde=0+memo(nums,n-1,dp);
  dp[n]= max(include,exculde);
  
  return dp[n];
}
int tabulization(vector<int>&nums,int n){
    vector<int>dp(n+1,0);
     dp[0]=nums[0];
     dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++) {
        int include = nums[i] + dp[i - 2]; // Include current element
        int exclude = dp[i - 1]; // Exclude current element
        dp[i] = max(include, exclude); // Store the maximum in dp[i]
    }
  return dp[n-1];   
}
  int spaceOpt(vector<int>&nums,int n){
        int prev2 = 0;
        int prev1 = nums[0];
        int curr = 0;
        for(int i = 1;i<=n;i++){
            int temp = 0;
            if(i-2>=0){
                temp = prev2;
            }
            int include = temp + nums[i];
            int exclude = 0 + prev1;
            curr = max(include,exclude);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
int main(){
    vector<int>nums={1,2,3,1};
    int n=nums.size();
    // int ans=maxRob(nums,n);
    // vector<int>dp(n+1,-1);
    // int ans=memo(nums,n,dp);
    int ans=tabulization(nums,n);
    cout<<"Maxiumum robeed is:"<<ans;
}
