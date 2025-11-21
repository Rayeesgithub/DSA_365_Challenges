Leetcode
Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

  concept-> for(int i = 0; i < s.size(); i++) {
    for(int j = i; j < s.size(); j++) {
        cout << s.substr(i, j - i + 1) << endl;
    }

s = "abc"
Indexes:
0 → a, 1 → b, 2 → c
Now let's generate substrings:
Case 1:
i = 0, j = 0
j - i + 1 = 0 - 0 + 1 = 1 → "a"

Case 2:
i = 0, j = 1
j - i + 1 = 1 - 0 + 1 = 2 → "ab"

Case 3:
i = 0, j = 2
j - i + 1 = 2 - 0 + 1 = 3 → "abc"



  //Appraoch1
  // Function to check if a string is a palindrome or not
bool checkPalindrome(string str){
    
    int left = 0; 
    int right = str.size() - 1; // last index of the string
    
    // Run loop until left pointer crosses right pointer
    while(left <= right){
        
        // If characters at left & right are not equal → Not a palindrome
        if(str[left] != str[right]){
            return false;
        }
        
        // Move inward
        left++;  
        right--;
    }
    
    return true; // If loop ends → it is a palindrome
}

int countSubstrings(string s) {

    int count = 0; // To store total palindrome substrings
    
    // Outer loop selects starting index 'i'
    for(int i = 0; i < s.size(); i++){
        
        // Inner loop selects ending index 'j'
        for(int j = i; j < s.size(); j++){
            
            // Extract substring from i → j (length = j-i+1)
            string sub = s.substr(i, j - i + 1);
            
            // Check if the extracted substring is a palindrome
            if(checkPalindrome(sub)){
                count++; // increase palindrome count
            }
        }
    }
    
    return count; // return total palindromic substrings
}


//2nd Apprach
// Function to count palindrome substrings by expanding around the center
int expandAroundIndex(string s, int i, int j) {
    int count = 0;

    // Expand while both pointers are inside string
    // and characters at both ends are same → palindrome condition
    while (i >= 0 && j < s.length() && s[i] == s[j]) {
        count++;   // found one valid palindrome substring
        i--;       // move left pointer backward
        j++;       // move right pointer forward
    }

    return count; // return how many palindromes found for this center
}

int countSubstrings(string s) {
    int count = 0;
    int n = s.length();

    for (int i = 0; i < n; i++) {

        // Check all palindromes of ODD length
        // Example: "aba" → center is 'b'
        int oddAns = expandAroundIndex(s, i, i);
        count = count + oddAns;

        // Check all palindromes of EVEN length
        // Example: "aa" → center is between two 'a'
        int even = expandAroundIndex(s, i, i + 1);
        count = count + even;
    }

    return count;  // total palindrome substrings
}
