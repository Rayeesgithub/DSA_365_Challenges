//https://www.geeksforgeeks.org/problems/lcm-and-gcd4516/1

Input: N1 = 9, N2 = 12

Output: 3
Explanation:
Factors of 9: 1, 3, 9
Factors of 12: 1, 2, 3, 4, 6, 12
Common Factors: 1, 3
Greatest common factor: 3 (GCD)
LCM: 36

    
//Approach1-Broute force       
Time Complexity = O(min(n1, n2)) && Space Complexity = O(1)
    
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n1 = 20, n2 = 15;   // Two numbers
    int gcd = 1;           // Variable to store GCD
    int lcm = 1;           // Variable to store LCM

    // Loop to find GCD (Greatest Common Divisor)
    for(int i = 1; i <= min(n1, n2); i++){
        
        // If i divides both numbers, then i is a common divisor
        if(n1 % i == 0 && n2 % i == 0){
            gcd = i;  // keep updating gcd; the largest value will stay at the end
        }
    }

    // Formula: LCM * GCD = n1 * n2  
    lcm = (n1 * n2) / gcd;

    cout << "GCD: " << gcd;
    cout << " LCM: " << lcm;
}



//Approach2-optimal
Time=O(log(min(n1, n2))),  space=O(1)

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n1 = 9, n2 = 112;   // Input numbers
    int gcd = 1;           // Variable to store the final GCD

    // Euclid's Algorithm using modulo
    while(n1 > 0 && n2 > 0){
        
        // If n1 is greater, replace n1 = n1 % n2
        if(n1 > n2){
            n1 = n1 % n2;
        }
        // Otherwise replace n2 = n2 % n1
        else{
            n2 = n2 % n1;
        }
    }

    // When one becomes 0, the other contains the GCD
    if(n1 == 0){
        gcd = n2;
    }
    else{
        gcd = n1;
    }

    cout << "GCD : " << gcd;
}


dry run
n1 = 9
n2 = 12
if(n1 > n2) → 9 > 12 ? → NO
so, n2 = n2 % n1
n2 = 12 % 9

12 = 9 × 1 = 9
12 - 9 = 3
So n2 = 3
Updated values:n1 = 9 , n2 = 3
n1 = n1 % n2
n1 = 9 % 3
n1 = 0
n2 = 3
After Loop
Since n1 == 0, gcd = n2 = 3
