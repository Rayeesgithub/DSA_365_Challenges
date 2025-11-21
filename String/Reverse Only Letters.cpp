Example 1:
Input: s = "ab-cd"
Output: "dc-ba"
Example 2:
Input: s = "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"


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
        else {
            // Both are alphabets → swap them
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }

    return s;
}
