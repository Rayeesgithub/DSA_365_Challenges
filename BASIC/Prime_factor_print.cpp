Input: N = 60
Output: 2, 3, 5  
Explanation: All factors/divisors of 60 include: 1, 2, 3, 4, 5, 6, 10, 12, 18, 20, 30, 60. Out of these only 2, 3 and 5 are prime.

Input: N = 35
Output: 5, 7
Explanation: All factors/divisors of 35 include: 1, 5, 7, 35. Out of these, only 5 and 7 are prime.


vector<int> getPrimeFactors(int n){ 
        // Declare a vector to store the prime factors of n.
        vector<int> primeFactors; 
        
        // Start a loop from 2 to n, iterating through each number i.
        for(int i = 2; i<=n; i++){ 
            // Check if n is divisible by i without any remainder.
            if(n%i==0){ 
                // If it is, call the function checkPrime to determine if i is prime.
                if(checkPrime(i)){ 
                    // If i is prime, add it to the vector of prime factors.
                    primeFactors.push_back(i); 
                }
            }
        }
        // Return the vector containing the prime factors of n.
        return primeFactors; 
    }
