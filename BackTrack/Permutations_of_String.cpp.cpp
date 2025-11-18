nput:  s = "ABC"
Output: "ABC", "ACB", "BAC", "BCA", "CAB", "CBA"


i = 0
 ├── swap(0,0) → "abc"
 │       └── i = 1
 │            ├── swap(1,1) → "abc" → permutation
 │            ├── swap(1,2) → "acb" → permutation
 │
 ├── swap(0,1) → "bac"
 │       └── i = 1
 │            ├── swap(1,1) → "bac" → permutation
 │            ├── swap(1,2) → "bca" → permutation
 │
 └── swap(0,2) → "cba"
         └── i = 1
              ├── swap(1,1) → "cba" → permutation
              ├── swap(1,2) → "cab" → permutation



  #include<bits/stdc++.h>
using namespace std;

// Function to generate all permutations of string s
void Permutation(string s, int i) {

    // BASE CASE:
    // If index i reaches the end, print the formed permutation
    if(i >= s.length()) {
        cout << s << " ";
        return;   // very important to stop further execution
    }

    // We try placing every character at position i
    for(int j = i; j < s.length(); j++) {

        // STEP 1: Swap character at i with character at j
        // Meaning: Fix s[j] at position i
        swap(s[i], s[j]);

        // STEP 2: Recur for next index i+1
        Permutation(s, i + 1);

        // STEP 3: Backtrack → Undo the swap to restore original string
        swap(s[i], s[j]);
    }
}

int main() {
    string s = "abc";
    int i = 0;
    Permutation(s, i);
}
