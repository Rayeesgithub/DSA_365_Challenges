https://leetcode.com/problems/roman-to-integer/description/
// striver sheet
Time Complexity: O(n),
Space Complexity: O(1)
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int romanToInt(string s) {
    // Create a map to store the integer values of Roman numerals
    unordered_map<char, int> roman = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int result = 0; 
    // Iterate through each character in the input string
    for (int i = 0; i < s.length(); i++) {
        // If the current character is less than the next character,
        // it means we have a subtractive combination (e.g., IV, IX)
        if (i + 1 < s.length() && roman[s[i]] < roman[s[i + 1]]) {
            result -= roman[s[i]]; // Subtract the value of the current character
        } else {
            result += roman[s[i]]; // Otherwise, add the value of the current character
        }
    }

    return result; // Return the final result
}

int main() {
    string romanNumeral = "MCMXCIV"; // Example Roman numeral
    // Convert the Roman numeral to an integer and print the result
    cout << "The integer value of " << romanNumeral << " is " << romanToInt(romanNumeral) << endl;
    return 0;
}
