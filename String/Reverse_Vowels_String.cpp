Input: s = "IceCreAm"
Output: "AceCreIm"
Explanation:
The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes "AceCreIm".

// Function to check if a character is a vowel
bool isVowel(char &c) {

    // Create a list of all vowels (both lowercase + uppercase)
    vector<char> ans = {'a','e','i','o','u','A','E','I','O','U'};

    // Check if the current character 'c' matches any vowel in the list
    for(char x : ans) {
        if(x == c) return true;   // If match found → return true
    }
    
    return false;   // If loop ends → char is NOT a vowel
}


string reverseVowels(string s) {

    int i = 0; 
    int j = s.size() - 1;   // Two pointer approach starting from both ends

    // Condition → until both pointers cross
    while(i <= j) {
        
        // If left pointer is NOT a vowel → move it right
        if(!isVowel(s[i])) {
            i++;
        }
        // Else if right pointer is NOT a vowel → move it left
        else if(!isVowel(s[j])) {
            j--;
        }
        // If both are vowels → swap them
        else {
            swap(s[i], s[j]);
            i++; 
            j--;  // Move both pointers toward center
        }
    }

    return s; // Final string with reversed vowels
}
