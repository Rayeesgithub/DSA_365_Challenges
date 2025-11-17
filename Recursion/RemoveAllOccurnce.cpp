Input: s = "daabcbaabcbc", part = "abc"
Output: "dab"


  // iterative approach

  explanation-> If ans = "da" → size = 2
part = "abc" → size = 3
2 < 3 → cannot match, so no need to check.

  ✅2. ans.substr(ans.size() - n)

This extracts the last n characters of ans.

Example:
ans = "daabc"
n = 3

ans.substr(ans.size()-3)
→ ans.substr(5-3)
→ ans.substr(2)
→ "abc"

So it extracts:
✔ the ending of ans

✅3. == part

We compare:

👉 Is the ending equal to "abc"?

If yes → remove "abc" from the end.

⭐4. ans.erase(ans.size() - n);

This removes the last n characters from ans.

Example:
ans = "daabc"
part = "abc"
output->da


  
  class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans = "";
        int n = part.size();

        for (char c : s) {
            ans.push_back(c);                 // Step 1: add character
            
            // Step 2: check if last characters match 'part'
            if (ans.size() >= n && ans.substr(ans.size()-n) == part) {
                ans.erase(ans.size() - n);    // remove part
            }
        }

        return ans;
    }
};


// Recursive
class Solution {
public:

    void solve(string &s, string &part, int i, string &ans) {
        // Base condition: when we reach the end of string
        if (i == s.size()) return;

        // Step 1: include current character
        ans.push_back(s[i]);

        int n = part.size();

        // Step 2: check if ans ends with part
        if (ans.size() >= n && ans.substr(ans.size() - n) == part) {
            ans.erase(ans.size() - n); // remove part
        }

        // Step 3: recursive call for next character
        solve(s, part, i + 1, ans);
    }

    string removeOccurrences(string s, string part) {
        string ans = "";
        solve(s, part, 0, ans);
        return ans;
    }
};


