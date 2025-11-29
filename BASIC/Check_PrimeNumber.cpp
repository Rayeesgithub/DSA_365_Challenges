Input=7
output= prime number
input=12
output=Not Prime Number

// Apprach 1
Time=O(n) && space=0(1)
bool checkPrime(int n){
    if(n < 2) return false;

    for(int i = 2; i < n; i++){
        if(n % i == 0)
            return false;   // found divisor → not prime
    }
    return true;            // no divisors found → prime
}


// optimal approach
Time=O(√n) && space=0(1)
bool checkPrime(int n){
    if(n < 2) return false;

    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0)
            return false;
    }

    return true;
}
