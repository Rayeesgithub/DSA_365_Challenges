class Solution {
  public:
    // Function to find the maximum number of cuts.
    int solve(int n,int x,int y,int z){
        if(n==0) return 0;
        if(n<0) return INT_MIN;
        
        int a=solve(n-x,x,y,z)+1;
        int b=solve(n-y,x,y,z)+1;
        int c=solve(n-z,x,y,z)+1;
        
       int  maxi=max(a,max(b,c));
       
       return maxi;
    }
    int maximizeTheCuts(int n, int x, int y, int z) {
       
        int ans=solve(n,x,y,z);
    }
};
