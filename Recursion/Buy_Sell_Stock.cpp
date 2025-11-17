Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.


  
class Solution {
public:
    int solve(vector<int>& prices, int i, int minPrice, int maxProfit) {
        // Base case: end of array
        if (i == prices.size()) return maxProfit;

        // Update min price so far
        minPrice = min(minPrice, prices[i]);

        // Update max profit so far
        maxProfit = max(maxProfit, prices[i] - minPrice);

        // Move to next index
        return solve(prices, i + 1, minPrice, maxProfit);
    }

    int maxProfit(vector<int>& prices) {
        return solve(prices, 0, INT_MAX, 0);
    }
};
