Input: s = "abba"
Output: true
Explanation: "abba" reads the same forwards and backwards, so it is a palindrome.

// Two Pointer

 bool isPalindrome(string& s) {
        // code here
        int left=0; int right=s.size()-1;
        
        while(left<=right){
            if(s[left]!=s[right]){
                return false;
            }
            left++; right--;
        }
        return true;
    }


// Recursive
bool CheckPalindrome(string &s,int left,int right){
      if(left>right){
          return false;
      }
      while(left<=right){
          if(s[left]!=s[right]){
              return false;
          }
          left++; right--;
      }
      return true;
  }
    bool isPalindrome(string& s) {
        // code here
        int left=0; int right=s.size()-1;
        bool ans=CheckPalindrome(s,left,right);
    }
};
