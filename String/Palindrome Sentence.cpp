Input: s = "Abc 012..## 10cbA"
Output: true
Explanation: If we remove all non-alphanumeric characters and convert all uppercase letters to lowercase, 
string s will become "abc01210cba" which is a palindrome.



Time: O(n),Space: O(n) (extra string)

  bool isPalinSent(string &s) {
    string ans = "";

    // Step 1: Remove non-alphanumeric characters
    // and convert all characters to lowercase
    for (int i = 0; i < s.size(); i++) {
        if (isalnum(s[i])) {                 // allows letters + digits
            ans.push_back(tolower(s[i]));    // safe lowercase conversion
        }
    }

    // Step 2: Two-pointer palindrome check
    int left = 0;
    int right = ans.size() - 1;

    while (left <= right) {
        if (ans[left] != ans[right]) {
            return false;   // not a palindrome
        }
        left++;
        right--;
    }

    return true;    // palindrome
}
