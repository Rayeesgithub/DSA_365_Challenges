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
      int minPrice=INT_MAX;
       int maxprofit=0; 
   for(int i=0; i<prices.size();i++){
        // If the current price is less than minPrice, update minPrice
        if(prices[i]<minPrice) minPrice=prices[i];
        else{  // Calculate the profit if the stock was bought at minPrice and sold at current price
          int  profit=prices[i]-minPrice;
            if(profit>maxprofit)  // If the calculated profit is greater than maxProfit, update maxProfit
              maxprofit=profit;
        }
      }  
      return maxprofit;
    }

int main() {
    vector<int> arr = {7,1,5,3,6,4};
    int maxPro = maxProfit(arr);
    cout << "Max profit is: " << maxPro << endl;
}
