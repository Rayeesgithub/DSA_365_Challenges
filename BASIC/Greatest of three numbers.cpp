Example 1:
Input: 1 3 5
Output: 5
Explanation: Answer is 5.Since 5 is greater than 1 and 3.

  Time Complexity: O(1), no extra time complexity is used.
Space Complexity: O(1), no extra space used.

  int main() {
    double num1 = 1, num2 = 3, num3 = 5;

  int ans=max(num1,max(num2,num3));

  cout<<ans;

}


//2nd appraoch
  void findGreatest() {
        double num1 = 1, num2 = 3, num3 = 5;

        if (num1 > num2 && num1 > num3) {
            cout << "The greatest of the three numbers is " << num1;
        }
        else if (num2 > num1 && num2 > num3) {
            cout << "The greatest of the three numbers is " << num2;
        }
        else {
            cout << "The greatest of the three numbers is " << num3;
        }
    }
