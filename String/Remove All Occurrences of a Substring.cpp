https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/

Input: s = "daabcbaabcbc", part = "abc"
Output: "dab"

// approach1
string removeOccurrences(string s, string part) {
        // Find the first occurrence (starting index) of substring 'part'
        int pos = s.find(part);

        // Loop while 'part' exists inside string s
       // Keep looping as long as the substring is found inside the main string.
     //  Loop will stop when no more "abc" found → pos becomes string::npos.  return substring not found
        while(pos != string::npos) { 

            // Remove substring 'part' from string s at position 'pos'
            // erase(starting_index, length_of_substring)
            s.erase(pos, part.size());

            // Search again for next occurrence after removal
            pos = s.find(part);
        }

        // Return modified string
        return s;
}


// optimal approach
string removeOccurrences(string s, string part) {

    // Continue while:
    // 1️⃣ The string still has characters
    // 2️⃣ The substring 'part' is still found inside `s`
    while(s.length() != 0 && s.find(part) < s.length()) {

        // Erase substring from where it is found
        s.erase(s.find(part), part.length());
    }

    // Return final processed string
    return s; 
}

