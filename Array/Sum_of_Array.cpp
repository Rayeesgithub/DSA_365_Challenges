Input: N = 5, array[] = {1,2,3,4,5}
Output: 15
Explanation: Sum of all the elements is 1+2+3+4+5 = 15


  // approach1  time=Time Complexity: O(N ) && space=0(1)
  int arraySum(vector<int>& arr) {
        // Initialize sum variable
        int sum = 0;

        // Loop through all elements
        for (int i = 0; i < arr.size(); i++) {
          
            sum += arr[i];
        }
        // Return the total sum
        return sum;
    }



//approach2   time=Time Complexity: O(N ) && space=0(1)
✅ Approach 2: Using accumulate() (No loop used by you)

C++ STL already internally uses a loop, but your code has NO loop.

  #include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int sum = accumulate(arr.begin(), arr.end(), 0);
    cout << sum;
}
