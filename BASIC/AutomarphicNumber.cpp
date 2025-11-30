Input Format: N = 76
Result: Automorphic Number
Explanation: Calculating 76 * 76 gives 5776, it ends with the given number.

  #include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 76;      // Given number
    int sq = n * n;  // Step 1: Calculate square of the number

    int temp = n;    // Copy of n (we will use it to extract digits)

    // Step 2: Compare last digits of square with original number
    // We check digit-by-digit
    bool flag = true;  // assume it's automorphic

    while (temp > 0) {
        int d1 = sq % 10; // last digit of square
        int d2 = temp % 10; // last digit of original number

        if (d1 != d2) {     // if any digit mismatches → not automorphic
            flag = false;
            break;
        }

        sq /= 10;   // remove last digit from square
        temp /= 10; // remove last digit from original number
    }

    // Step 3: Print result
    if (flag)
        cout << "Automorphic Number";
    else
        cout << "Not Automorphic";

    return 0;
}
