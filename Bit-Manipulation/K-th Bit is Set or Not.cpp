// striver sheet

//broute force
#include <iostream>
#include <vector>
using namespace std;

bool checkKthBit(int n, int k) {
    vector<int> binary;  // To store the binary representation
    
    // Convert the number to binary
    while (n > 0) {
        binary.push_back(n % 2);
        n = n / 2;
    }
    // Now, check if the k-th bit exists and is set
    if (k < binary.size() && binary[k] == 1) {
        return true;
    } else {
        return false;
    }
}int main() {
    int n = 5;  // Example number
    int k = 2;  // Example bit position
    if (checkKthBit(n, k)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}


//optimal approach
bool checkKthBit(int n, int k) {
        // Your code here
        // It can be a one liner logic!! Think of it!!
         return (n & (1 << k)) != 0;
    }
