//https://leetcode.com/problems/two-sum/
//striver sheet
class Solution {
public:
     // approach1-broute force Time Complexity: O(N2), Space Complexity: O(1)
   vector<int> twoSum(vector<int>& nums, int target) {

    int n = nums.size();        // size of array
    vector<int> ans;            // to store result indices

    for (int i = 0; i < n; i++) {    
        // pick first element one by one
       
        for (int j = i + 1; j < n; j++) { 
            // pick the second element after i (avoid i == j)

            // check if both numbers add up to target
            if (nums[i] + nums[j] == target) {

                ans = {i, j};   // store indices
            }
        }
    }

    return ans; // returns empty if no pair found
}



         
         //approach2
         approach1-broute force Time Complexity: O(N), Space Complexity: O(1)
 #include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == target) {
            return {left, right};   // indices found
        }
        else if (sum < target) {
            left++;  // need a bigger sum
        }
        else {
            right--; // need a smaller sum
        }
    }

    return {-1, -1};  // not found
}




    //3rd approach
 

vector<int> twoSum(int n, vector<int> &arr, int target) {

    unordered_map<int, int> mp;     // value → index

    for (int i = 0; i < n; i++) {

        int num = arr[i];           // current value
        int first = target - num;   // the value we need to find

        // If complement exists in map → we found the pair
        if (mp.find(first) != mp.end()) {
            return { mp[first], i };   // return indices
        }

        mp[num] = i;   // store current number with index
    }

    return { -1, -1 };   // if no pair exists
}

int main()
{
    int n = 3;
    vector<int> arr = {3,2,4};
    int target = 6;
    vector<int> ans = twoSum(n, arr, target);
    cout << "This is the answer ;" << ans[0] << ", "
         << ans[1] << endl;
    return 0;
}
};
