https://leetcode.com/problems/rotate-string/description/
//striver sheet

//broute force
#include <string>
using namespace std;

bool rotateString(string s, string goal) {
    // If the sizes of the strings are different, they cannot be rotations of each other.
    if (s.size() != goal.size()) return false;

    // Iterate through each character of the goal string.
    for (int i = 0; i < goal.length(); i++) {
        bool ans = true; // Assume the current rotation matches s.

        // Check if the current rotation of goal matches s.
        for (int j = 0; j < s.length(); j++) {
            // Use modulo to wrap around the goal string and compare with s.
            if (goal[(i + j) % goal.length()] != s[j]) {
                ans = false; // If any character doesn't match, this rotation isn't valid.
                break; // No need to check further for this rotation.
            }
        }

        // If a valid rotation is found, return true.
        if (ans) {
            return true;
        }
    }
 // If no valid rotation is found, return false.
    return false


// optimal-approach
bool rotateString(string s, string goal) {
    // If the lengths of the strings are not equal, they cannot be rotations of each other
    if (s.size() != goal.size()) return false;
    
    // Concatenate s with itself. This will contain all possible rotations of s as substrings.
    string concatenated = s + s;
    
    // Check if goal is a substring of the concatenated string
    if (concatenated.find(goal) != string::npos) {
        return true;
    }
    
    return false;
}
