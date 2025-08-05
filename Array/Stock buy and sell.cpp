//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
//striver sheet

//broute force
 int maxProfit(vector<int>& prices) {
      // broute force 
    //   int maxprofit=0;
    //   for(int i=0;i<prices.size();i++){
    //     for(int j=i+1; j<prices.size();j++){
    //         if(prices[j]>prices[i]){
    //             maxprofit=max(maxprofit,prices[j]-prices[i]);
    //         }
    //     }
    //   }

   
    // optimal approach
       int maxProfit(vector<int>& prices) {
    int n=prices.size();     int miniElement=INT_MAX;
        int maxiProfit=INT_MIN;
        for(int i=0; i<n; i++){
         miniElement=min(miniElement,prices[i]);
         maxiProfit=max(maxiProfit,prices[i]-miniElement);

    }
     return maxiProfit;   
    }



//  New Appraoch

int FindMaximum(int arr[],int n){
   int buy=INT_MAX; int index;int sell=0; int profit=0;
   for(int i=0; i<n; i++){
   if(buy>arr[i]){
    buy=arr[i];
    index=i;
   }
   }
   for(int i=index; i<n; i++){
    sell=max(sell,arr[i]);
   }
   profit=sell-buy;
   if(profit<0) return 0;
  return profit;
}
int main() {
    vector<int> arr = {7,1,5,3,6,4};
    int maxPro = maxProfit(arr);
    cout << "Max profit is: " << maxPro << endl;
}
