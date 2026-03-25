
3        <-- T (Number of test cases)

10 20    <-- Test Case 1
5 15     <-- Test Case 2
100 200  <-- Test Case 3

  
int t;
cin >> t;

while(t--) {
   solve();
}
void solve() {
    // Yahan apna actual logic likhein
    int a, b;
    cin>>a>>b;
    
    cout << (a + b) << endl; 
}

⭐-> Kabhi-kabhi T nahi diya hota, bas bola jata hai "read until end of input". Uske liye ye code use karein:

int main() {
    int a, b;
    // Jab tak input mil raha hai, loop chalega
    while (cin >> a >> b) {
        cout << a + b << endl;
    }
    return 0;
}
