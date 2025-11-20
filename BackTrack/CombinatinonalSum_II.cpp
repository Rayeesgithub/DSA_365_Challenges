Note: The solution set must not contain duplicate combinations.
Input: candidates = [10,1,2,7,6,1,5], target = 8

Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]]


Explanation: These are the unique combinations whose sum is equal to target.


#include<bits/stdc++.h>
using namespace std;

void CombinationalSumII(vector<int>&arr, vector<vector<int>>&ans, vector<int> output,
int index, int target){

    // If target becomes 0 → we found a valid combination
    if(target == 0){
        ans.push_back(output);
        return;
    }

    // If target goes negative → no need to continue
    if(target < 0) return;


    // -------------------------------------------
    //  ⭐ THIS LOOP IS THE MAIN LOGIC ⭐
    // -------------------------------------------
    for(int i = index; i < arr.size(); i++){

        // Skip duplicate values at the same recursion level
        // Example: [1,2,2,2,5] → so that we don't pick the same “2” again
        if(i > index && arr[i] == arr[i-1]) continue;

        // Only pick the number if it is ≤ target
        if(arr[i] <= target){

            // Choose the number
            output.push_back(arr[i]);

            // Move to next index (i+1) because one number can be used only once
            CombinationalSumII(arr, ans, output, i + 1, target - arr[i]);

            // Backtrack
            output.pop_back();
        }
    }
}

int main() {
  vector<int>arr = {2,5,2,1,2};
  int target = 5;

  // Sort array so duplicates come together
  sort(arr.begin(), arr.end());   // arr becomes: [1,2,2,2,5]

  vector<vector<int>> ans;
  vector<int> output;

  CombinationalSumII(arr, ans, output, 0, target);

  for(int i=0; i<ans.size(); i++){
      for(int j=0; j<ans[i].size(); j++){
          cout << ans[i][j] << " ";
      }
      cout << endl;
  }
}




Explanation-> What does the loop do?
  [1, 2, 2, 2, 5]
If index = 0, loop checks:
  i=0 → 1
i=1 → 2
i=2 → 2
i=3 → 2
i=4 → 5

  If index = 2, loop checks:

i=2 → 2
i=3 → 2
i=4 → 5

This loop allows:

1. Each number to be used only once
Because next recursive call uses i+1

2. Avoids duplicate combinations
if(i > index && arr[i] == arr[i-1]) continue;
If we are at the same depth of recursion

And the number is same as the previous number
➡️ then skip it to avoid duplicate subsets.

  At index = 1:

i = 1 → 2 (pick)
i = 2 → 2 (SAME as arr[1]) → SKIP
i = 3 → 2 (SAME as arr[1]) → SKIP

TREE
  f(0,5,[])
 ├── i=0 pick 1 → f(1,4,[1])
 │      ├── i=1 pick 2 → f(2,2,[1,2])
 │      │        ├── i=2 pick 2 → f(3,0,[1,2,2]) ✓
 │      │        ├── i=3 skip (duplicate)
 │      │        └── i=4 too big
 │      ├── i=2 skip duplicate
 │      └── i=3 skip duplicate
 │
 ├── i=1 pick 2 → f(2,3,[2])
 │      ├── i=2 pick 2 → f(3,1,[2,2])
 │      │      ├── i=3 skip
 │      │      └── i=4 too big
 │      ├── i=3 skip duplicate
 │      └── i=4 too big
 │
 ├── i=2 skip duplicate
 ├── i=3 skip duplicate
 └── i=4 pick 5 → f(5,0,[5]) ✓
