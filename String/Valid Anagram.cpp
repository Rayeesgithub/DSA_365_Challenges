//https://leetcode.com/problems/valid-anagram/description/

//striver

// broute force
 bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        for(int i=0; i<max(s.size() ,t.size()); i++){
            if(s[i]!=t[i]){
                return false;
            }
        }
        return true;
    }



// optimal Approach
bool isAnagram(string s, string t) {
    unordered_map<char, int> mp; // Create an unordered map to store the frequency of characters

    // Increment the count for each character in string s
    for (int i = 0; i < s.length(); i++) {
        mp[s[i]]++;
    }

    // Decrement the count for each character in string t
    for (int j = 0; j < t.length(); j++) {
        mp[t[j]]--;
    }

    // Check if all counts are zero
    // If any character count is not zero, s and t are not anagrams
    for (auto i : mp) {
        if (i.second != 0) {
            return false; // Found a mismatch in character count
        }
    }

    return true; // All character counts match, so s and t are anagrams
}
