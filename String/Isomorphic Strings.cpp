https://leetcode.com/problems/isomorphic-strings/description/

Input: s = "paper", t = "title"
Output: true
Input: s = "foo", t = "bar"
Output: false
    
// Approach1   Time	O(n) — Single pass with constant check  &&  Space	O(1)
bool isIsomorphic(string s, string t) {

    // hash[] will store mapping: s[i] → t[i]
    // isMap[] will check whether t[i] is already used for some mapping
    int hash[256] = {0};
    bool isMap[256] = {0};

    // Traverse every character of both strings
    for(int i = 0; i < s.size(); i++) {
        
        // If s[i] is not mapped yet AND t[i] is not taken yet
        if(hash[s[i]] == 0 && isMap[t[i]] == false) {
            
            // Create mapping s[i] → t[i]
            hash[s[i]] = t[i];

            // Mark t[i] as already mapped
            isMap[t[i]] = true;
        }
    }

    // Check if mapping is correct for all characters
    for(int i = 0; i < s.size(); i++) {
        
        // If stored mapped character does NOT match expected t[i]
        if(char(hash[s[i]]) != t[i]) {
            return false;
        }
    }

    return true; // All characters follow correct mapping → isomorphic
}


// apprach2- Timen O(n)
bool isIsomorphic(string s, string t) {

    int n = s.length();
    int m = t.length();

    // We create two arrays to store the LAST SEEN index of each character
    vector<int> indexS(300, 0); // For characters in string s
    vector<int> indexT(300, 0); // For characters in string t

    // If lengths differ → Not isomorphic
    if(n != m) {
        return false;
    }

    // Loop through every character
    for(int i = 0; i < n; i++) {

        // If the last seen position of s[i] and t[i] are different,
        // then mapping is inconsistent → Not isomorphic
        if(indexS[s[i]] != indexT[t[i]]) {
            return false;
        }

        // Store the current index (i+1 because default was 0)
        // Mark the latest position where this character appeared
        indexS[s[i]] = i + 1;
        indexT[t[i]] = i + 1;
    }

    // All mappings were consistent → Strings are isomorphic
    return true;
}
