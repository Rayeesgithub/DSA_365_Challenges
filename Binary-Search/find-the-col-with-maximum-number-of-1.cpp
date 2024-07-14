


#include <bits/stdc++.h>
using namespace std;

int colWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    int cnt_max = 0;
    int index = -1;

    //traverse the matrix:
    for (int i = 0; i < n; i++) {
        int cnt_ones = 0;
        int j = 0;
        for (; j < m; j++) {
            cnt_ones += matrix[j][i];
        }
        if (cnt_ones > cnt_max) {
            cnt_max = cnt_ones;
            index = j;
        }
    }
    return index;
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 1}};
    int n = 3, m = 3;
    cout << "The col with maximum no. of 1's is: " <<
         colWithMax1s(matrix, n, m) << '\n';
}

