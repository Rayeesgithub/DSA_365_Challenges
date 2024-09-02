//selg

#include<bits/stdc++.h>
using namespace std;

bool checkPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i< n; i++) {  // Corrected loop condition to optimize prime checking
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n = 35;
    vector<int> ans1;

    // Collect all prime numbers up to n
    for (int i = 2; i <= n; i++) {
        if (checkPrime(i)) {
            ans1.push_back(i);
        }
    }

    // Print all prime factors of n
    for (int i = 0; i < ans1.size(); i++) {
        if (n % ans1[i] == 0) {
            cout << ans1[i] << " ";
        }
    }

    return 0;
}
