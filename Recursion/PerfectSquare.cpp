Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.


int solve(int n) {
        if (n == 0) return 0;   // 0 squares needed
        if (n < 0) return INT_MAX; // invalid case

        int ans = INT_MAX;

        for (int i = 1; i * i <= n; i++) {   // correct loop: i*i <= n
            int perfctSqr = i * i;
            int sub = solve(n - perfctSqr);
            if (sub != INT_MAX) {
                ans = min(ans, 1 + sub);
            }
        }

        return ans;
    }

    int numSquares(int n) {
        return solve(n);
    }
