class Solution {
public:

    // Recursive function to find the maximum number of cuts
    int solve(int n, int x, int y, int z) {

        // If length becomes exactly zero → no more cuts needed, this is a valid way
        if(n == 0) return 0;

        // If length becomes negative → this path is invalid, return very small number
        if(n < 0) return INT_MIN;

        // Try cutting the rod by length 'x'
        // If this cut is valid, we add 1 cut and solve for remaining length (n-x)
        int a = solve(n - x, x, y, z) + 1;

        // Try cutting the rod by length 'y'
        int b = solve(n - y, x, y, z) + 1;

        // Try cutting the rod by length 'z'
        int c = solve(n - z, x, y, z) + 1;

        // Take the maximum number of cuts possible among all three choices
        int maxi = max(a, max(b, c));

        return maxi;  // return the maximum number of cuts for length 'n'
    }

    int maximizeTheCuts(int n, int x, int y, int z) {

        // Call the recursive function to get result
        int ans = solve(n, x, y, z);

        // NOTE: Missing return statement in your code. Correct is:
        return ans;
    }
};
