#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the 1D array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements for the 1D array:" << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "1D Array elements are: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
