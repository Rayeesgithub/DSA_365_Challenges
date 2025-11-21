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
isdigit(ch)
isalnum(ch)
islower(ch)
isupper(ch)
isspace(ch)
14. String to Number
stoi(s)
stoll(s)
15. Number to String
to_string(num)
