https://leetcode.com/problems/sum-of-beauty-of-all-substrings/description/
// striver-sheet

// broute force
#include <iostream>
#include <unordered_map>
#include <climits>
#include <string>
using namespace std;
\\time complexity is O(n^2)   space complexity is O(1)
int beautySum(string s) {
    int n = s.length(); 
    int sum = 0;  // Initialize the total beauty sum

    // Iterate over all possible starting indices for substrings
    for (int i = 0; i < n; i++) {
        unordered_map<char, int> mp;  // Initialize a map to store character frequencies

        // Iterate over all possible ending indices for substrings starting from i
        for (int j = i; j < n; j++) {
            mp[s[j]]++;  // Increment the frequency of the current character

            int maxi = INT_MIN;  // Initialize the maximum frequency to the smallest integer
            int mini = INT_MAX;  // Initialize the minimum frequency to the largest integer

            // Iterate over the frequency map to find the maximum and minimum frequency
            for (auto it : mp) {
                maxi = max(maxi, it.second);
                mini = min(mini, it.second);
            }

            int ans = maxi - mini;  // Calculate the beauty of the current substring
            sum += ans;  // Add the beauty of the current substring to the total sum
        }
    }

    return sum;  // Return the total beauty sum
}
int main() {
    string s = "aabcb";
    cout << "Total beauty sum: " << beautySum(s) << endl;
    return 0;
}
