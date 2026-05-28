// https://leetcode.com/problems/valid-anagram/description/

Input: s = "anagram", t = "nagaram"

Output: true

// Broute Force 
  T.C-> O(nlogn) S.C-> O(1) 
 bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t ? true : false;
    }

// Bettter approach
//Time Complexity: O(N) && Space Complexity: O(1)

bool isAnagram(string s, string t) {
       if(s.size()!=t.size()){
        return false;
       } 

       unordered_map<char,int>mp;
       for(int i=0; i<s.size(); i++){
        mp[s[i]]++;
        mp[t[i]]--;
       }

       for(auto it: mp){
        if(it.second!=0){
            return false;
        }
       }
   return true;
    }
};


  // Dry run->
  Step 2: Loop 1 (Frequency Mapping)

We initialize an empty map: mp = {}. The loop runs from i = 0 to 2.

i = 0:
s[0] is 'c' → mp['c']++ → Map becomes {'c': 1}
t[0] is 'a' → mp['a']-- → Map becomes {'c': 1, 'a': -1}
i = 1:
s[1] is 'a' → mp['a']++ → Map becomes {'c': 1, 'a': 0}
t[1] is 'c' → mp['c']-- → Map becomes {'c': 0, 'a': 0}
i = 2:
s[2] is 't' → mp['t']++ → Map becomes {'c': 0, 'a': 0, 't': 1}
t[2] is 't' → mp['t']-- → Map becomes {'c': 0, 'a': 0, 't': 0}

Step 3: Loop 2 (Verification)

We iterate through the elements of mp:

Element 1: {'c': 0} → it.second == 0 (Valid, continue)
Element 2: {'a': 0} → it.second == 0 (Valid, continue)
Element 3: {'t': 0} → it.second == 0 (Valid, continue)




// frequency method
bool isAnagram(string s, string t) {

    if(s.size() != t.size()){
        return false;
    }

    vector<int> freq(26,0);

    for(int i=0; i<s.size(); i++){
        freq[s[i]-'a']++;
        freq[t[i]-'a']--;
    }

    for(int i=0; i<26; i++){
        if(freq[i] != 0){
            return false;
        }
    }

    return true;
}
