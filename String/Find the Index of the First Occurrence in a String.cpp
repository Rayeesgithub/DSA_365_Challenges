https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

//striver sheet

int strStr(string haystack, string needle) {
    // Initialize the index variable to -1, which will store the first occurrence of the needle
    int index = -1;

    // Get the lengths of the haystack and needle strings
    int n = haystack.length();
    int m = needle.length();

    // If the needle is an empty string, return 0 as per problem definition
    if (m == 0) return 0;

    // Loop through the haystack up to the point where there's enough remaining length to match the needle
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
