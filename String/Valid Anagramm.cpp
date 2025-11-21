leetcode
Input: s = "anagram", t = "nagaram"
Output: true
Example 2:
Input: s = "rat", t = "car"
Output: false

   
#include<bits/stdc++.h>
using namespace std;

//approach1 T.C-> nlogn
bool isAnagram(string s, string t) {

       // Step 1: Sort both strings alphabetically
       sort(s.begin(), s.end());
       sort(t.begin(), t.end());

       // Step 2: If sorted strings are equal → they contain same characters
       if(s != t){
          return false; // Not anagrams
       }

       return true; // Yes, anagrams
}



// approach2-> T.C=0(n) & S.C=0(1)
bool isAnagram(string s, string t) {

        unordered_map<char, int> mp; // Store character frequency

        // Count frequency of all characters in s
        for(int i = 0; i < s.size(); i++){
            mp[s[i]]++;
        }

        // Reduce frequency for characters present in t
        for(int i = 0; i < t.size(); i++){
            mp[t[i]]--;
        }

        // If every character frequency becomes zero → Anagram
        for(auto it : mp){
            if(it.second != 0){
                return false;
            }
        }

        return true; // Strings are anagrams
}



// approach3
// approach3->  T.C=0(n) & S.C=0(1)
bool checkAnagram(string st1, string st2){

    // If lengths are different → not anagrams
    if(st1.length() != st2.length()) return false;

    // Frequency array for 26 letters only
    int freq[26] = {0};

    // Count characters of first string
    for(int i = 0; i < st1.length(); i++){
        freq[st1[i] - 'A']++;   // Convert character to index (0–25)
    }

    // Reduce count using second string
    for(int i = 0; i < st2.length(); i++){
        freq[st2[i] - 'A']--;
    }

    // If all frequencies become zero → valid anagram
    for(int i = 0; i < 26; i++){
        if(freq[i] != 0){
            return false;
        }
    }

    return true;
}


int main(){
    string st1; string st2;
    cin>>st1; cout<<endl; cin>>st2; cout<<endl;
    if(checkAnagram(st1,st2)){
        cout<<"Yes This Anagram";
    }
    else{
        cout<<"No this is Not Anagram";
    }

}






  bool isAnagram(string s, string t) {
        unordered_map<char,int>mp;
        for(int i=0; i<s.length();i++){
            mp[s[i]]++;
        }
        for(int j=0; j<t.length(); j++){
            mp[t[j]]--;
        }

        for(auto i:mp){
            if(i.second!=0){
                return false;
            }
        }
        return true;
    }
