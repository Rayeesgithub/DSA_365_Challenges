Example 1:
Input:N = 12345
Output:5 

  //Time-com->0(logn) and space-com-> 0(1)
  
#include <iostream>
using namespace std;

// Function to count how many digits are in a number
int countDigits(int n){
  
    int cnt = 0;      // Step 1: Initialize counter to 0
  
    // Step 2: Run loop until number becomes 0
    while(n > 0){
   
        cnt = cnt + 1;   // Count one digit
        
        n = n / 10;      // Remove the last digit from the number
                         // Example: 329823 -> 32982 -> 3298 -> ...
    }
  
    return cnt;          // Step 3: Return total digit count
}



int main() {
    int N = 329823;        // Sample number
    cout << "N: "<< N << endl;

    int digits = countDigits(N);   // Calling the function

    cout << "Number of Digits in N: "<< digits << endl;  // Output
    return 0;
}


✅ Dry Run (Step-by-Step Execution)
| Step        | n value | cnt value | Explanation       |
| ----------- | ------- | --------- | ----------------- |
| Start       | 329823  | 0         | Initialize        |
| Iteration 1 | 32982   | 1         | One digit counted |
| Iteration 2 | 3298    | 2         | Another digit     |
| Iteration 3 | 329     | 3         | →                 |
| Iteration 4 | 32      | 4         | →                 |
| Iteration 5 | 3       | 5         | →                 |
| Iteration 6 | 0       | 6         | Loop stops        |



                                
                            
