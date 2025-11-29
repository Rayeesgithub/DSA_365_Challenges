1                 1
1 2             2 1
1 2 3         3 2 1
1 2 3 4     4 3 2 1


  #include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 4;

    for(int i = 1; i <= n; i++) {

        // LEFT side: 1 to i
        for(int j = 1; j <= i; j++) {
            cout << j << " ";
        }

        // SPACES in middle
        int spaces = 2 * (n - i);
        for(int s = 0; s < spaces; s++) {
            cout << "  ";
        }

        // RIGHT side: i to 1
        for(int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        cout << endl;
    }

    return 0;
}
