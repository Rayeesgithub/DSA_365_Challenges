Input: N = 12345
Output:54321
Explanation: The reverse of 12345 is 54321.

  //Time-com=0(logn) spacecom=0(1)

    
class Solution {
public:
    int reverse(int n) {
   long long int ans=0;
   while(n != 0) {        // Loop until all digits are processed

        int digit = n % 10;   // Extract last digit
     
       // Build reversed number
        ans = ans * 10 + digit;
       
        n = n / 10;           // Remove last digit from n
    } 
          return ans;
    }
   
};

