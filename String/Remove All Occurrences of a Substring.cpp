https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/
// love Babbar

// broute force
 string removeOccurrences(string s, string part) {
            string result = "";

    for (char c : s) {
        result += c;  // Push current character to result

        // Check if the end of `result` contains `part`
        if (result.size() >= part.size() && 
            result.substr(result.size() - part.size()) == part) {
            // Remove the occurrence of `part`
            result.erase(result.size() - part.size());
        }
    }

    return result;
    }


// optimal approach
string removeOccurrences(string s, string part) {
    while(s.length() != 0 && s.find(part) < s.length()) { //  // Continue looping while `s` is not empty and `part` is found in `s`
        s.erase(s.find(part), part.length());   // Remove the substring `part` from `s` starting at `index`
    }
    return s; 
}
