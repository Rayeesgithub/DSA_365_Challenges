    * 
   * * 
  * * * 
 * * * * 
* * * * *




#include <iostream>
using namespace std;

int main() {
    int n= 5;

    for (int row = 0; row< n; row++) {
        // Print leading spaces
        for (int space = 0; space < n - row - 1; space++) {
            cout << " ";
        }

        // Print stars with space
        for (int star = 0; star <=row; star++) {
            cout << "* ";
        }

        cout << endl;
    }

    return 0;
}
