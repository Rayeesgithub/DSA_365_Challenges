https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1

    
// Approach-1: Using loop logic with find()
int strStr(string haystack, string needle) {
    
    // Loop every index where a substring can start
    for(int i = 0; i + needle.size() <= haystack.size(); i++) {

        // Check if substring from index i matches needle
        if(haystack.substr(i, needle.size()) == needle) {
            return i;  // First match found → return index
        }
    }
    
    return -1; // No match found

//2nd appraoch
 // Approach-2: Using built-in find() function
int strStr(string haystack, string needle) {
    int index = haystack.find(needle);  // Find first occurrence
    
    if(index != string::npos) {  // If substring found
        return index; 
    }
    
    return -1; // If substring not found
}


// appraoch3 
int strStr(string haystack, string needle) {
    // Initialize the index variable to -1, which will store the first occurrence of the needle
    int index = -1;
 int n = haystack.length(); int m = needle.length();
    for (int i = 0; i <= n - m; i++) {
        // Extract the substring from haystack starting at index i with length m
        // Compare it with the needle
        if (haystack.substr(i, m) == needle) {
            // If a match is found, set the index to i
            index = i;
            // Break out of the loop as we found the first occurrence
            break;
        }
    }
    // Return the index of the first occurrence of needle in haystack, or -1 if not found
    return index;
}
