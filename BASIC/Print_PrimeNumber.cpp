Input=18
output= Prime Numbers: 2 3 5 7 11 13 17


Time =0(n^2) &&  space=0(1)
#include<bits/stdc++.h>
using namespace std;

// Function to check if a number is prime or not
bool checkPrime(int n){
    if(n < 2) return false;        // 0 and 1 are NOT prime numbers

    // Check divisibility from 2 to n-1
    for(int i = 2; i < n; i++){
        if(n % i == 0)            // If divisible, not prime
            return false;
    }
    return true;                  // No divisors → prime
}

int main(){
    int n = 18;

    cout << "Prime Numbers: ";

    // Print all prime numbers from 1 to n-1
    for(int i = 1; i < n; i++){
        if(checkPrime(i)){        // Check each number is prime
            cout << i << " ";     // Print prime number
        }
    }
}
