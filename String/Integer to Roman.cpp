https://leetcode.com/problems/integer-to-roman/description/
// striver sheet

string intToRoman(int num) {
    // Store major Roman numeral values
    vector<int> integer = {
        1000, 900, 500, 400,
        100, 90, 50, 40,
        10, 9, 5, 4, 1
    };

    // Store corresponding Roman symbols in the same order
    vector<string> roman = {
        "M", "CM", "D", "CD",
        "C", "XC", "L", "XL",
        "X", "IX", "V", "IV", "I"
    };

    string ans = "";

    // Traverse each Roman numeral value
    for(int i = 0; i < integer.size(); i++) {

        // Keep subtracting the largest possible value
        // and append corresponding Roman symbol
        while(num >= integer[i]) {
            num -= integer[i];     // subtract from number
            ans += roman[i];       // append roman symbol
        }
    }

    return ans; // return final Roman numeral string
}


input num=58
| Step | Condition    | Action           | Remaining num | Resulting ans |
| ---- | ------------ | ---------------- | ------------- | ------------- |
| 1    | 58 >= 1000 ❌ | skip             | 58            | ""            |
| 2    | 58 >= 900 ❌  | skip             | 58            | ""            |
| 3    | 58 >= 500 ❌  | skip             | 58            | ""            |
| 4    | 58 >= 400 ❌  | skip             | 58            | ""            |
| 5    | 58 >= 100 ❌  | skip             | 58            | ""            |
| 6    | 58 >= 90 ❌   | skip             | 58            | ""            |
| 7    | 58 >= 50 ✅   | subtract → 58-50 | 8             | "L"           |
| 8    | 8 >= 50 ❌    | skip             | 8             | "L"           |
| 9    | 8 >= 40 ❌    | skip             | 8             | "L"           |
| 10   | 8 >= 10 ❌    | skip             | 8             | "L"           |
| 11   | 8 >= 9 ❌     | skip             | 8             | "L"           |
| 12   | 8 >= 5 ✅     | subtract → 8-5   | 3             | "LV"          |
| 13   | 3 >= 5 ❌     | skip             | 3             | "LV"          |
| 14   | 3 >= 4 ❌     | skip             | 3             | "LV"          |
| 15   | 3 >= 1 ✅     | subtract → 3-1   | 2             | "LVI"         |
| 16   | 2 >= 1 ✅     | subtract → 2-1   | 1             | "LVII"        |
| 17   | 1 >= 1 ✅     | subtract → 1-1   | 0             | "LVIII"       |
