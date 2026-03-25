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


#### 
