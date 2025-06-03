* * * * * 
 * * * * 
  * * * 
   * * 
    *

#include <iostream>
using namespace std;

int main() {
    int n= 5;

    for (int row = 0; row< n; row++) {
        // Print leading spaces
        for (int space = 0; space < row; space++) {
            cout << " ";
        }

        // Print stars with space
        for (int star = 0; star<n-row; star++) {
            cout << "* ";
        }

        cout << endl;
    }

    return 0;
}
