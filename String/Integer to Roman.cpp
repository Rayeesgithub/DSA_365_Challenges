https://leetcode.com/problems/integer-to-roman/description/
// striver sheet

string intToRoman(int num) {
    // Define the values and corresponding Roman numerals
    vector<int> integer = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> roman = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    string ans = ""; // Initialize the result string to store the Roman numeral

    // Iterate through each value from largest to smallest
    for (int i = 0; i < integer.size(); i++) {
        // Append the corresponding numeral to the result while subtracting the value from num
        while (num >= integer[i]) {
            num = num - integer[i]; // Subtract the value from num
            ans = ans + roman[i]; // Append the corresponding numeral to the result string
        }
    }

    return ans; // Return the final result
}
