Q-> Return the fewest number of coins that you need to make up that amount
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1


  ⭐ Explanation in Simple Words
solve(coins, amount) returns:

👉 Minimum number of coins needed to make amount.

How it works?
If amount == 0 → no coins needed → return 0.
If amount < 0 → invalid way → return INT_MAX.
Try every coin:
Take that coin.
Reduce the amount.
Recursively solve the remaining amount.Pick the minimum of all valid options.
  
  class Solution {
public:

// Recursive function to find minimum coins required
int solve(vector<int>& coins, int amount){

    // Base case: If amount becomes 0, no more coins needed
    if(amount == 0) return 0;

    // If amount becomes negative, this path is invalid → return "infinite"
    if(amount < 0) return INT_MAX;

    int mini = INT_MAX;   // store minimum coins required

    // Try every coin
    for(int i = 0; i < coins.size(); i++){

        // Choose coin[i] and solve the remaining amount
        int result = solve(coins, amount - coins[i]);

        // If result is valid (not INT_MAX), update mini
        if(result != INT_MAX){
            // 1 coin used now + result of subproblem
            mini = min(mini, 1 + result);
        }
    }

    // Return the minimum coins needed for this amount
    return mini;
}

int coinChange(vector<int>& coins, int amount) {

    // Call recursive function
    int ans = solve(coins, amount);

    // If ans still INT_MAX → no solution
    if(ans == INT_MAX){
        return -1;
    }

    // Otherwise return the minimum number of coins
    return ans;
}
};
