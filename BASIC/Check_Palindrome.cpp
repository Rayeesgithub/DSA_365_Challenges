//https://leetcode.com/problems/palindrome-number/
class Solution {
public:
    bool isPalindrome(int x) {
        
        int ans=0;
        int original=x; // here you mistake
        if(x<0) return false;
        while(x>0){
            int digit=x%10;
            if((ans>INT_MAX/10)) return 0;
            ans=ans*10+digit;
            x=x/10;
        }
        if(ans==original){
            return true;
        }
      else{
        return false;
      }
      
    }
};
