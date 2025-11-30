Example 1:
Input: 1996
Output: Yes
Explanation: Since 1996 is a leap year answer is “Yes”.

Example 2:
Input: 2000
Output: Yes
Explanation: Since 2000 is a leap year answer is “Yes”.

Time & space Complexity: O(1)

bool isLeap(int year) {

    // Rule 1: If divisible by 400 → always leap year
    if (year % 400 == 0)
        return true;

    // Rule 2: If divisible by 4 AND NOT divisible by 100 → leap year
    if (year % 4 == 0 && year % 100 != 0)
        return true;

    // Otherwise → not a leap year
    return false;
}
