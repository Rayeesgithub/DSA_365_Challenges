Example 1:
Input: s = "ab-cd"
Output: "dc-ba"
Example 2:
Input: s = "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"


📌 What is isalpha() ?

isalpha(ch) is a function from <cctype> library used to check if a character is a letter (A–Z or a–z).

| Character               | `isalpha()` result |
| ----------------------- | ------------------ |
| `'A'` `'g'` `'Z'`       | ✅ true             |
| `'1'` `'-'` `'@'` `' '` | ❌ false            |

  
  Time Complexity=O(N)  &&  Space Complexity=O(1)
string reverseOnlyLetters(string s) { 
    int i = 0; 
    int j = s.size() - 1;

    // Loop until left pointer crosses right pointer
    while(i < j) {

        // If s[i] is NOT an alphabet → move forward
        if(!isalpha(s[i])) {
            i++;
        }
        // Else if s[j] is NOT an alphabet → move backward
        else if(!isalpha(s[j])) {
            j--;
        }
        else {  // if(isalpha(s[left]) && isalpha(s[right])){
            // Both are alphabets → swap them
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }

    return s;
}
