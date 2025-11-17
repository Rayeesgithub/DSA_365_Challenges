Input: num1 = "11", num2 = "123"
Output: "134"




What is -'0' ?
  num1[p1] - '0' ->  It converts the character digit into an integer.
  char c = '5';
int x = c - '0';  // x = 5

✅ 2. What is +'0' ?
Meaning: It converts an integer digit  into a character .
  int digit = 7;
char c = digit + '0';  // c = '7'




class Solution {
public:

// Recursive helper function
void solve(string &num1, int p1, string &num2, int p2, int carry, string &ans) {

    // BASE CASE: when both strings are fully processed
    if(p1 < 0 && p2 < 0){
        if(carry != 0){
            ans.push_back(carry + '0');  // add leftover carry
        }
        return;
    }

    // take digit from num1 if p1 valid, otherwise take '0'
    int n1 = (p1 >= 0 ? num1[p1] : '0') - '0';

    // take digit from num2 if p2 valid, otherwise take '0'
    int n2 = (p2 >= 0 ? num2[p2] : '0') - '0';

    // sum of digits + carry
    int csum = n1 + n2 + carry;

    int digit = csum % 10;   // current digit to store
    carry = csum / 10;       // new carry for next recursion

    ans.push_back(digit + '0');  // store digit in answer

    // recursive call for next digits (move left side)
    solve(num1, p1 - 1, num2, p2 - 1, carry, ans);
}

// main function
string addStrings(string num1, string num2) {
    string ans = "";
    
    // start recursion from last index of both strings
    solve(num1, num1.size() - 1, num2, num2.size() - 1, 0, ans);

    // since digits are stored in reverse order, reverse final answer
    reverse(ans.begin(), ans.end());

    return ans;
}
};
