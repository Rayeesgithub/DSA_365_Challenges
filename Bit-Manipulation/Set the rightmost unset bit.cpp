//
int setRightmostUnsetBit(int n) {
    // Set the rightmost unset bit of n
    return n | (n + 1);
}

int main() {
    int n;
    cin >> n;
    cout << setRightmostUnsetBit(n) << endl;
    return 0;
}
