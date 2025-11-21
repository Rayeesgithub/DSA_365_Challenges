✅Input
String str;
cin >> str ///Taking input in string
getline (cin, Str); // To read spaces also

✅ Frequently Used STL for String & Character
🔹 1. Length / Size
  s.length()
   s.size()

🔹 2. Access Characters
s[i]         // access char
s.front()    // first char
s.back()     // last char

🔹 3. Modify String
s.push_back('a')
s.pop_back()
s.append("abc")
s += "xyz"

🔹 4. Substring
  s.substr(pos, length)      // substring
  string t = s.substr(2, 5);

🔹 5. Find Functions
s.find("abc")
s.find('a')

🔹 7. Insert / Erase
  s.insert(pos, "abc")
s.erase(pos, len)

🔹 9. Sorting Characters
sort(s.begin(), s.end());

🔹 10. Reverse String
reverse(s.begin(), s.end());

🔹 11. Remove Spaces / Characters
s.erase(KONposition,Kitnalength);

🔹 12. Convert Case
tolower(ch)
toupper(ch)

13. Check Character Type
isalpha(ch)
📌 What is isalpha() ?

isalpha(ch) is a function from <cctype> library used to check if a character is a letter (A–Z or a–z).

| Character               | `isalpha()` result |
| ----------------------- | ------------------ |
| `'A'` `'g'` `'Z'`       | ✅ true             |
| `'1'` `'-'` `'@'` `' '` | ❌ false            |


| Function        | One-sentence meaning                                                                    |
| --------------- | --------------------------------------------------------------------------------------- |
| **isdigit(ch)** | Checks whether the character `ch` is a numeric digit (0–9).                             |
| **isalnum(ch)** | Checks whether the character `ch` is either a letter or a digit (A–Z, a–z, 0–9).        |
| **islower(ch)** | Checks whether the character `ch` is a lowercase letter (a–z).                          |
| **isupper(ch)** | Checks whether the character `ch` is an uppercase letter (A–Z).                         |
| **isspace(ch)** | Checks whether the character `ch` is a whitespace character (space, tab, newline etc.). |

14. String to Number
stoi(s)
stoll(s)
15. Number to String
to_string(num)
