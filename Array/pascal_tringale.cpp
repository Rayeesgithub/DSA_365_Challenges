https://leetcode.com/problems/pascals-triangle/description/
striver

  //broute force
  class Solution {
public:
    // Function to calculate the binomial coefficient nCr
    int nCr(int n, int r) {
        long long res = 1;
        // Handle edge cases where r is 0 or n
        if (r > n - r) {
            r = n - r;
        }
        // Calculate nCr
        for (int i = 0; i < r; i++) {
            res = res * (n - i);
            res = res / (i + 1);
        }
        return (int)(res);
    }

    vector<vector<int>> generate(int numRows) {
        // Resultant 2D vector to store Pascal's Triangle
        vector<vector<int>> ans;

        // Iterate through each row
        for (int row = 0; row < numRows; row++) {
            vector<int> temp;
            // Iterate through each element in the row
            for (int col = 0; col <= row; col++) {
                // Calculate binomial coefficient for current element
                temp.push_back(nCr(row, col));
            }
            // Add the row to the resultant 2D vector
            ans.push_back(temp);
        }

        return ans;
    }
};

//optimal approach
     // Resultant 2D vector to store Pascal's Triangle
        vector<vector<int>> ans;

        // Iterate through each row
        for (int i = 0; i < numRows; i++) {
            // Initialize the current row with 1s
            vector<int> row(i + 1, 1);

            // Update the inner elements of the row based on the previous row
            for (int j = 1; j < i; j++) {
                row[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }

            // Add the current row to the resultant 2D vector
            ans.push_back(row);
        }

        return ans;
    }
