// Fixed sized array
#include <bits/stdc++.h>
using namespace std;

void markRow(int arr[][100], int n, int m, int i) {
    for (int j = 0; j < m; j++) {  // Loop until 'm', the number of columns
        if (arr[i][j] != 0) {
            arr[i][j] = -1;
        }
    }
}

void markCol(int arr[][100], int n, int m, int j) {
    for (int i = 0; i < n; i++) {  // Loop until 'n', the number of rows
        if (arr[i][j] != 0) {
            arr[i][j] = -1;
        }
    }
}

void setZero(int arr[][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                markRow(arr, n, m, i);
                markCol(arr, n, m, j);
            }
        }
    }
    
    // Set all marked -1 positions to 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == -1) {
                arr[i][j] = 0;
            }
        }
    }
}int main() {
    int n, m;
    cin >> n >> m;
    int arr[100][100];  // Set max array size here

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    setZero(arr, n, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;  // Print new line after each row
    }
  return 0;}





// Dynamic size array you used vector
#include <bits/stdc++.h>
using namespace std;

void markRow(vector<vector<int>>& arr, int n, int m, int i) {
    for (int j = 0; j < m; j++) {
        if (arr[i][j] != 0) {
            arr[i][j] = -1;
        }
    }
}

void markCol(vector<vector<int>>& arr, int n, int m, int j) {
    for (int i = 0; i < n; i++) {
        if (arr[i][j] != 0) {
            arr[i][j] = -1;
        }
    }
}

void setZero(vector<vector<int>>& arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                markRow(arr, n, m, i);
                markCol(arr, n, m, j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == -1) {
                arr[i][j] = 0;
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter the number of rows: ";
    cin >> n;
    cout << "Enter the number of columns: ";
    cin >> m;

    vector<vector<int>> arr(n, vector<int>(m)); // Create a dynamic 2D vector based on user input

    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    setZero(arr, n, m);

    cout << "Resultant array:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
