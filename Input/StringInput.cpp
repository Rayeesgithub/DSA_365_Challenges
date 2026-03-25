#### 🔥 1. String Input (Without Space)
👉 Input: hello

string s;
cin >> s;

Output-> ( i/p-> hellow, output-> hellow, i/p->L O V E  then o/p-> only L)
💡->❌ cin >> stops at first whitespace.  Agar input mein sentence hai (e.g., "TCS NQT 2026"), toh sirf cin >> s karne par sirf "TCS" read hoga.

####🔥 2. String Input (With Spaces)
👉 Input: hello world
string s;
getline(cin, s);
cout<<s;

o/p-> hellow world (it will print white space evven)

⚠️ Common mistake: 
int n;
cin >> n;  // reads 3, leaves '\n' in buffer
getline(cin, s);  // reads the leftover '\n' → s is EMPTY!  // ❌ will skip input 

 ❌ cin >> leaves a newline \n in the buffer. getline immediately reads it and returns empty string. Test case fails!
🔴 Common Mistake: cin >> n; ke baad turant getline(cin, s); use karna. Isse getline purani newline read kar leta hai aur empty string deta hai.

✅ Correct way: fix — add cin.ignore() between them
 int n;
cin >> n;
cin.ignore();   // important
getline(cin, s);

Example-> int n;
string s;

cin >> n;
cin.ignore();
getline(cin, s);

cout << "n = " << n << endl;
cout << "s = " << s << endl;

Outpput-> 
n = 5
s = Hello World ✅
⭐ Rule: Always add cin.ignore() before getline if you used cin >> before it.

case2-> Multiple lines of strings
input:   3  →  Hello  →  World  →  Bye
int n; cin >> n;
cin.ignore();                     // clear '\n' once
vector<string> v(n);
for(int i=0; i<n; i++)
    getline(cin, v[i]);  
