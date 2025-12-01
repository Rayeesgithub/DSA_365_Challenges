//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note: That buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.


// Brute Force Approach
// Check every possible pair (i < j) and calculate profit
// Time Complexity: O(n^2)

// Example: For each day i, check selling on every future day j

int maxProfit(vector<int>& prices) {
    int maxprofit = 0;

    for (int i = 0; i < prices.size(); i++) {

        for (int j = i + 1; j < prices.size(); j++) {

            // If selling price is greater → profit possible
            if (prices[j] > prices[i]) {
                maxprofit = max(maxprofit, prices[j] - prices[i]);
            }
        }
    }

    return maxprofit;
}


   
    // optimal approach
       // Optimal Approach → One-pass solution
// Idea: Track the minimum price seen so far and calculate max profit
// Time Complexity: O(n)
// Space Complexity: O(1)

int maxProfit(vector<int>& prices) {
    int n = prices.size();

    int miniElement = INT_MAX;   // To store minimum price so far
    int maxiProfit = 0;          // Max profit

    for (int i = 0; i < n; i++) {

        // Step 1: Update minimum price so far
        miniElement = min(miniElement, prices[i]);

        // Step 2: Calculate profit if sold today
        maxiProfit = max(maxiProfit, prices[i] - miniElement);
    }

    return maxiProfit;
}




//  New Appraoch
// New Approach – Two Pass Method
// Pass 1: Find the minimum buy price and its index
// Pass 2: From that index, find maximum selling price
// Time Complexity: O(n)
// Space Complexity: O(1)

int FindMaximum(int arr[], int n) {

    int buy = INT_MAX;  // Minimum buy price
    int index = 0;      // Store index of minimum price
    int sell = 0;       // Maximum selling price after buy
    int profit = 0;     

    // Pass 1 → Find minimum element and its index
    for (int i = 0; i < n; i++) {

        if (buy > arr[i]) {  
            buy = arr[i];  // Update minimum price
            index = i;     // Store its position
        }
    }

    // Pass 2 → From that index, find the maximum selling price
    for (int i = index; i < n; i++) {
        sell = max(sell, arr[i]);  // Find max value after buy
    }

    // Final profit
    profit = sell - buy;

    // Profit cannot be negative → return 0
    if (profit < 0) return 0;

    return profit;
}
int main() {
    vector<int> arr = {7,1,5,3,6,4};
    int maxPro = maxProfit(arr);
    cout << "Max profit is: " << maxPro << endl;
}
