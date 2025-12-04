Input:
 Nums = [1,2,-1,1,3,1]
Output:
 2,-1,3
Explanation:
 1 is the only element in the given array which occurs thrice in the array. -1,2,3 occurs only once and hence,
these are non-repeating elements of the given array.



  // approach1
// approach 1
// Time Complexity: O(n^2) → nested loops
// Space Complexity: O(n) → visited[] array

vector<bool> visited(arr.size(), false);  // keeps track of which elements are already counted

for (int i = 0; i < arr.size(); i++) {

    // if this element is already counted earlier, skip it
    if (visited[i] == true) {
        continue;
    }

    int count = 0;

    // check this element with every other element
    for (int j = 0; j < arr.size(); j++) {
        if (arr[i] == arr[j]) {
            count++;          // count occurrences
            visited[j] = true; // mark duplicate as visited
        }
    }

    // if count == 1 → element is non-repeating
    if (count == 1) {
        cout << arr[i] << " ";
    }
}




// 2nd approach  ✔ Time: O(n) ✔ Space: O(n)

#include<bits/stdc++.h>
using namespace std;

int main() {
   int n = 6;
   int arr[n] = {1, 2, -1, 1, 3, 1};

   unordered_map<int, int> mp;

   // Count frequencies of each element → O(n)
   for (int i = 0; i < n; i++) {
      mp[arr[i]]++;
   }

   // Print elements whose count is 1 → non-repeating
   for (auto it : mp) {
      if (it.second == 1) {
         cout << it.first << " ";
      }
   }
}




// approach3  time=nlogn space=1
#include<bits/stdc++.h>
using namespace std;

void findNonRepeatingElement(vector<int>& nums) {
    
    sort(nums.begin(), nums.end());  // Sorting array

    // Check 1st element separately
    if (nums[0] != nums[1])
        cout << nums[0] << " ";

    // Check middle elements
    for (int i = 1; i < nums.size() - 1; i++)
        if (nums[i-1] != nums[i] && nums[i] != nums[i+1])
            cout << nums[i] << " ";

    // Check last element separately
    if (nums[nums.size() - 2] != nums[nums.size() - 1])
        cout << nums[nums.size() - 1];
}

int main() {
    vector<int> nums = {1,2,-1,1,3,1};
    cout << "Non-repeating numbers are: " << endl;
    findNonRepeatingElement(nums);

    return 0;
}
