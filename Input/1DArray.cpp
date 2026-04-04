### 🔥 1. Array Input (Fixed Size)
5
1 2 3 4 5

int n;
cin >> n;

int arr[n];  OR  vector<int> arr(n);
for(int i = 0; i < n; i++) {
    cin >> arr[i];
}


### 2. 🟥 Two arrays, each on a new line
input:   1 2 3   (newline)   4 5 6
int n=3;
vector<int> a(n), b(n);
for(int i=0; i<n; i++) cin >> a[i];
for(int i=0; i<n; i++) cin >> b[i];
// cin>> handles newline between arrays fine


### 🔥 3. Array Input (Unknown Size/Continuous Input )
👉 Input: 1 2 3 4 5 ......

-> cin >> returns false at EOF(end of input)  — this loop ends automatically. Works for any type.
vector<int> arr;
int x;
// Read integers until EOF
while(cin >> x) {
    arr.push_back(x);
}

case2-> Read lines until EOF

input:   line1  →  line2  →  ... (no count)
while(getline(cin, line)){
    // process line
}

case 3-> Read pairs until EOF
input:   1 a  →  2 b  →  ...
int n; char c;
while(cin >> n >> c){
    // process n and c
}


#### 🔥 3. String Format Array Input
👉 Input: 1 2 3 4 5
    string s;
getline(cin, s);

stringstream ss(s);
int x;

while(ss >> x) {
    cout << x << " ";
}

Example-> input Format  —  "1 2 3 4 5"  (whole line as string)
#include <bits/stdc++.h>
using namespace std;
int main(){
    string line;
    getline(cin, line);       // reads: "1 2 3 4 5"

   stringstream ss(line);   // wrap string as stream
    vector<int> arr;
    int num;

    while(ss >> num)          // extract ints one by one
        arr.push_back(num);

    for(int x : arr) cout << x << " ";
}

HOW it works
1
getline(cin, line) reads the entire line including spaces into a string.
2
istringstream ss(line) treats that string exactly like a cin stream.
3 . ss >> num extracts integers one by one, skipping spaces automaticall

input format
5
10 20 30 40 50
code
int n; cin >> n;
cin.ignore();           // clears leftover '\n' — REQUIRED
string line;
getline(cin, line);

istringstream ss(line);
vector<int> arr;
int num;
while(ss >> num) arr.push_back(num);
Always add cin.ignore() after cin>>n before getline — without it getline reads an empty line!




##### 🔥 2) Comma Separated Array
👉 Input: 1,2,3,4,5

    #include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    vector<int> arr;
    string temp; // to store each split part

    stringstream ss(s);
    
    // getline(ss, temp, ',') →
   // splits string using ',' as delimiter
   // Example: "1,2,3" → "1", "2", "3"
    while(getline(ss, temp, ',')) {
        arr.push_back(stoi(temp));
    }

    for(int i : arr) cout << i << " ";
}




##### 🔥 3) Bracket 
👉  Input Format  —  [1,2,3,4,5]  or  {1,2,3,4,5}

    #include <bits/stdc++.h>
using namespace std;
int main(){
    string line;
    getline(cin, line);   // reads "[1,2,3,4,5]"

    // replace brackets AND commas with space
    for(char& c : line)
        if(c=='['||c==']'||c=='{'||c=='}'||c==',')
            c = ' ';
    // line is now: "  1 2 3 4 5  "

    istringstream ss(line);
    vector<int> arr;
    int num;
    while(ss >> num)      // handles multiple spaces fine
        arr.push_back(num);

    for(int x : arr) cout << x << " ";
}



#### 🔥 4) String of Space Separated Words

👉 Input: hello world from tcs

#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    stringstream ss(s);
    string word;

    vector<string> words;
    while(ss >> word) {
        words.push_back(word);
    }

    for(string w : words) cout << w << endl;
}




### 6 Two array in string form
arr1=[1,2,3,4,5]
arr2=[3,4,5,6,7]

vector<int>parse(string &str){

   for(char &c: str){
      if(c=='[' || c==']' || c==',' ){
         c=' ';
      }
   }

   stringstream ss(str);
   vector<int>arr;
   int num;

   while(ss>>num){
      arr.push_back(num);
   }
   return arr;
}
int main(){
   // string with space lena hai
  
   string str1,str2;
   getline(cin,str1);
   getline(cin,str2);

   vector<int>arr1=parse(str1);
   vector<int>arr2=parse(str2);
    cout<<"printing:";
   for(int i=0; i<arr1.size(); i++){
    cout<<arr1[i]<<" ";
   }
   

}
