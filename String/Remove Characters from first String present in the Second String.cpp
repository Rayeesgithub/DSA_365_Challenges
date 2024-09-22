#include<bits/stdc++.h>
using namespace std;

void removeDuplicate(string st1, string st2) {
    // Get the lengths of the two input strings
    int m = st1.length(); 
    int n = st2.length(); 
    
    string ans; 
    unordered_map<char, int> mp; 
    
    // Populate the map with the characters from the second string (st2)
    // Mark each character from st2 with value '1' in the map
    for (int i = 0; i < n; i++) {
        mp[st2[i]] = 1; 
    }
    
    // Loop through the first string (st1)
    for (int i = 0; i < m; i++) {
        // Check if the current character from st1 is not in st2 (i.e., not in the map)
        // If it's not in the map (mp[st1[i]] != 1), print the character
        if (mp[st1[i]] != 1) {
            cout << st1[i] << " ";  
        }
    }
}

int main() {
    string st1 = "abcdef";  // First string to compare
    string st2 = "cefz";    // Second string (contains characters to be removed from st1)
  
    removeDuplicate(st1, st2);
}
