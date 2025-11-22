Input: strs = ["eat","tea","tan","ate","nat","bat"]

Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Time->	O(N × K log K) & Space (map storage)	O(N × K)

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    
    // Map to store: sorted string → group of original strings (anagrams)
    map<string, vector<string>> mp;

    // Loop through each word in input
    for(auto str : strs) {

        string s = str;        // Copy the string
        sort(s.begin(), s.end());  
        // Sorting makes all anagrams identical
        // Example: "eat", "tea", "ate" → "aet"

        // Store original string into the map under sorted key
        mp[s].push_back(str);
    }

    // Convert map values into a vector of groups
    vector<vector<string>> ans;
    for(auto it : mp) {
        ans.push_back(it.second);  
        // it.second = list of anagram words
    }

    // Return final grouped anagrams
    return ans;
}


| Word  | Sorted Key | Stored Under Key      |
| ----- | ---------- | --------------------- |
| "eat" | "aet"      | ["eat"]               |
| "tea" | "aet"      | ["eat","tea"]         |
| "bat" | "abt"      | ["bat"]               |
| "ate" | "aet"      | ["eat", "tea", "ate"] |
