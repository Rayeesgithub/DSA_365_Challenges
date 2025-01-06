Sample Input 1:
2
10
7
Sample Output 1:
55
13
Explanation For Sample Output 1:
For the first test case, the 10th Fibonacci number is 55.
For the second test case, the 7th Fibonacci number is 13.



int main() {
    int t;
    cin >> t; // Number of test cases
    
    while (t--) {
        int n;
        cin >> n; // Input the position in the Fibonacci sequence
        cout << fibonacci(n) << endl; // Output the nth Fibonacci number
    }
    return 0;
}
