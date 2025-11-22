P   A   H   N
A P L S I I G
Y   I   R


Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"

  string convert(string s, int numRows) {

    // If only one row → zigzag pattern does NOT change the string
    if(numRows == 1) {
        return s;
    }

    // Create a vector of strings to store characters of each row
    vector<string> zigzag(numRows);

    int row = 0;   // current row index
    int dir = -1;  // direction (-1 = up, +1 = down)

    // Traverse all characters in the string
    for(int i = 0; i < s.length(); i++) {

        // Whenever reach top row (0) or bottom row (numRows-1),
        // reverse direction
        if(row == 0 || row == numRows - 1) {
            dir = -dir;
        }

        // Insert character into the current row bucket
        zigzag[row] += s[i];

        // Move row index based on direction
        if(dir == 1)
            row++;
        else
            row--;
    }

    // Merge all rows to form the final zigzag string
    string ans = "";
    for(auto r : zigzag) {
        ans += r;
    }

    return ans;
}



dry run
s = "PAYPALISHIRING"
numRows = 3
Zigzag index pattern for 3 rows:

less
Copy code
Row 0: P   A   H   N
Row 1: A P L S I I G
Row 2: Y   I   R
| i  | s[i] | Row | Direction | zigzag Result    |
| -- | ---- | --- | --------- | ---------------- |
| 0  | P    | 0   | change ↓  | Row0 = "P"       |
| 1  | A    | 1   | ↓         | Row1 = "A"       |
| 2  | Y    | 2   | change ↑  | Row2 = "Y"       |
| 3  | P    | 1   | ↑         | Row1 = "AP"      |
| 4  | A    | 0   | change ↓  | Row0 = "PA"      |
| 5  | L    | 1   | ↓         | Row1 = "APL"     |
| 6  | I    | 2   | change ↑  | Row2 = "YI"      |
| 7  | S    | 1   | ↑         | Row1 = "APLS"    |
| 8  | H    | 0   | change ↓  | Row0 = "PAH"     |
| 9  | I    | 1   | ↓         | Row1 = "APLSI"   |
| 10 | R    | 2   | change ↑  | Row2 = "YIR"     |
| 11 | I    | 1   | ↑         | Row1 = "APLSII"  |
| 12 | N    | 0   | change ↓  | Row0 = "PAHN"    |
| 13 | G    | 1   | ↓         | Row1 = "APLSIIG" |
