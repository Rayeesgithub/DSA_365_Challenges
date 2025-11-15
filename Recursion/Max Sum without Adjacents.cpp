Input: arr[] = [5, 5, 10, 100, 10, 5]
Output: 110
Explanation: If you take indices 0, 3 and 5, then = 5+100+5 = 110.


  class Solution {
  public:
    // calculate the maximum sum with out adjacent
    
    void solve(vector<int>&arr,int sum,int &maxi,int i){
        if(i>=arr.size()) {
            maxi=max(maxi,sum);  
            return;
        }
       
        
        solve(arr,sum+arr[i],maxi,i+2);
        solve(arr,sum,maxi,i+1);
    }
    int findMaxSum(vector<int>& arr) {
        int i=0;
        int sum=0;
        int maxi=INT_MIN;
        solve(arr,sum,maxi,i);
        return maxi;
    }
};
