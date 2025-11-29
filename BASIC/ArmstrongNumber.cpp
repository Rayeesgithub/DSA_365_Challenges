//https://www.geeksforgeeks.org/problems/armstrong-numbers2727/1
Example 1:
Input:N = 153
Output:True
Explanation: 1^3+5^3+3^3 = 1 + 125 + 27 = 153


    Time= ✔ O(log n) && space=O(1)
    #include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 1531;            // Input number
    string s = to_string(n); // Convert number to string
    int len = s.size();      // Count digits (length of number)

    int ans = 0;             // To store the sum of powered digits
    int original = n;        // Save original number for comparison

    // Loop to check Armstrong condition
    while(n != 0){
        int digit = n % 10;        // Extract last digit
        ans = ans + pow(digit, len); // Add digit raised to power of length
        n = n / 10;                 // Remove last digit
    }

    // Compare result with original number
    if(original == ans)
        cout << "Amstrong Number";
    else
        cout << "Not amstrong Number";
}



















//   public:
//     string armstrongNumber(int n){
//         int k=to_string(n).length();
//         long long int sum=0;
//         int num=n;
//         while(n>0){
//            int digit=n%10;
//            sum=sum+pow(digit,k);
//            n=n/10;
//         }
//         return sum == num ? "Yes" : "No";
//     }

