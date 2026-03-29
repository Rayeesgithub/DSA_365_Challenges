StriverNqt
Input: N = 8, array[] = {1,2,3,2,4,3,1,2}
Output: 2 2 2 1 1 3 3 4 
Explanation: Since  2 is present 3 times in an array , so print it 3 times 
    ,then print ‘1’ 2 times and then ‘3’ 2 times and 4 has least frequency, it will be printed at last.


    
#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int, int>& a, pair<int, int>& b) {
    // If frequencies are the same, sort by element value in ascending order
    if (a.second == b.second) {
        return a.first < b.first;
    }
    // Otherwise, sort by frequency in descending order
    return a.second > b.second;
}
vector<int> sortByFrequency(vector<int>& arr) {
    unordered_map<int, int> freqMap;

    // Count the frequency of each element
    for (int num : arr) {
        freqMap[num]++;
    }

    // Store the frequency and element as pairs in a vector
    vector<pair<int, int>> freqArray;
    for (auto& it : freqMap) {
        freqArray.push_back(it);
    }

    // Sort the vector by frequency and value
    sort(freqArray.begin(), freqArray.end(), compare);

    // Build the result array
    vector<int> result;
    for (auto& it : freqArray) {
        for (int i = 0; i < it.second; i++) {
            result.push_back(it.first);
        }
    }

    return result;
}
int main() {
   int N = 8;
    vector<int> arr = {1, 2, 3, 2, 4, 3, 1, 2};

    // Get the sorted array by frequency
    vector<int> sortedArray = sortByFrequency(arr);

    // Print the result
    for (int num : sortedArray) {
        cout << num << " ";
    }

    return 0;

}



//2nd approach
Input: N = 8, array[] = {1,2,3,2,4,3,1,2}
Output: 2 2 2 1 1 3 3 4 



void solve(vector<int>& arr){

   // unordered_map → stores frequency of each element
   // key = element, value = count
   unordered_map<int,int> mp;

   // Step 1: count frequency
   for(int i = 0; i < arr.size(); i++){
      mp[arr[i]]++;   // increase frequency of element
   }

   // Step 2: custom comparator (lambda function)
   // used to decide sorting order
   auto cmp = [&](int a, int b){

      // if frequency is different
      // element with higher frequency should come first
      if(mp[a] != mp[b]) 
         return mp[a] > mp[b];

      // if frequency is same
      // smaller element should come first
      return a < b;
   };

   // Step 3: sort array using custom comparator
   sort(arr.begin(), arr.end(), cmp);

   // Step 4: print sorted array
   for(auto it : arr){
      cout << it << " ";
   }
}
