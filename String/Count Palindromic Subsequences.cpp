Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".



time=0(n^3) && space=0(1)

// Function to check whether a string is palindrome or not
bool checkPalindrome(string str){

    int left = 0;                  // pointer at start of string
    int right = str.size() - 1;    // pointer at end of string

    // Compare characters from both ends
    while(left <= right){

        // If characters don't match → not a palindrome
        if(str[left] != str[right]){
            return false;
        }

        // Move pointers towards center
        left++;
        right--;
    }


  "a"   → palindrome ✔
"ab"  → ❌
"abc" → ❌
"b"   → ✔
"bc"  → ❌
"c"   → ✔

    // All characters matched → palindrome
    return true;
}

int countSubstrings(string s) {

    int count = 0;   // to store total palindromic substrings

    // Pick starting index of substring
    for(int i = 0; i < s.size(); i++){

        // Pick ending index of substring
        for(int j = i; j < s.size(); j++){

            // Extract substring from index i to j
            // j - i + 1 is the length of substring
            string sub = s.substr(i, j - i + 1);

            // Check if the substring is palindrome
            if(checkPalindrome(sub)){
                count++;   // increment count if palindrome
            }
        }
    }

    // Return total count of palindromic substrings
    return count;
}
