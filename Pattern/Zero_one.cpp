1
0 1
1 0 1
0 1 0 1
1 0 1 0 1


  #include <bits/stdc++.h>
using namespace std;

int main() {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j <= i; j++) {
            cout << 1 - ((i + j) % 2) << " ";
        }
        cout << endl;
    }
}
