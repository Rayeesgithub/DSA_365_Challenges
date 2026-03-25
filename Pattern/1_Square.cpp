* * * * * 
* * * * * 
* * * * * 
* * * * * 
* * * * *

#include <iostream>
using namespace std;

int main() {
    int n = 4; // size of the square

    for (int i = 1; i <= n; i++) {        // outer loop: rows (1 to 4)
        for (int j = 1; j <= n; j++) {    // inner loop: columns (1 to 4)
            cout << "* ";
        }
        cout << endl; // go to next line after each row
    }
    return 0;
}
```


