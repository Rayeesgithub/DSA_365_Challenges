by self
#include <iostream>
#include <cmath>
using namespace std;

int binaryToDecimal(int binaryNum) {
    int decimalNum = 0;
    int i = 0;

    while (binaryNum > 0) {
        int lastDigit = binaryNum % 10;
      
        decimalNum=decimalNum+lastDigit*pow(2,i++);
         binaryNum = binaryNum / 10;
    }

    return decimalNum;
}

int main() {
    int binaryNum;
    cout << "Enter a binary number: ";
    cin >> binaryNum;

    int decimalNum = binaryToDecimal(binaryNum);

    cout << "Decimal equivalent: " << decimalNum << endl;

    return 0;
}
