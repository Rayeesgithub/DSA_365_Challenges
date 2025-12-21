https://leetcode.com/problems/isomorphic-strings/description/

Input: s = "paper", t = "title"
Output: true
Input: s = "foo", t = "bar"
Output: false
    
// Approach1   Time	O(n) — Single pass with constant check  &&  Space	On1)

class Solution {
public:
    bool isIsomorphic(string s, string t) {

        // Map to store the FIRST index where each character appears in string s
        unordered_map<char, int> charIndexS;

        // Map to store the FIRST index where each character appears in string t
        unordered_map<char, int> charIndexT;

        // Traverse both strings together
        for (int i = 0; i < s.length(); i++) {

            // If character s[i] is appearing for the first time,
            // store its index
            if (charIndexS.find(s[i]) == charIndexS.end()) {
                charIndexS[s[i]] = i;
            }

            // If character t[i] is appearing for the first time,
            // store its index
            if (charIndexT.find(t[i]) == charIndexT.end()) {
                charIndexT[t[i]] = i;
            }

            // If the first occurrence index of s[i] and t[i]
            // are not the same, pattern is broken
            // → strings are NOT isomorphic
            if (charIndexS[s[i]] != charIndexT[t[i]]) {
                return false;
            }
        }

        // If all characters follow the same pattern
        return true;        
    }
};



    dry-Run-> s = "egg"
             t = "add"
charIndexS = {}
charIndexT = {}
✅ i = 0
s[i] = 'e'
t[i] = 'a'  
Check in charIndexS:

'e' not present → store , charIndexS['e'] = 0
Check in charIndexT:

'a' not present → store, charIndexT['a'] = 0
Compare
charIndexS['e'] == charIndexT['a']
0 == 0  ✔

✅ i = 1
charIndexS['g'] = 1
charIndexT['d'] = 1
comapre ,1 == 1 ✔
✅ i = 2
s[i] = 'g'
t[i] = 'd'
Already present → no update
charIndexS['g'] = 1
charIndexT['d'] = 1
comapre, 1 == 1 ✔

end loop return true


❌ Failure Case Dry Run
s = "ab"
t = "aa"
charIndexS['a'] = 0
charIndexT['a'] = 0
0 == 0 ✔
when i=1
s[i] = 'b'
t[i] = 'a'
charIndexS['b'] = 1
charIndexT['a'] = 0
comapre->1 != 0 ❌ return false
    
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
