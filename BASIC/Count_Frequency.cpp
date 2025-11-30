// Input: arr[] = {10,5,10,15,10,5};
// Output: 10  3
// 	      5  2
//          15  1
// Explanation: 10 occurs 3 times in the array 5 occurs 2 times in the array  15 occurs 1 time in the array




//	     broute force  Time Complexity: O(N*N)  Space Complexity: O(n)
#include <bits/stdc++.h>
using namespace std;
 
void countFreq(int arr[], int n)
{
    vector<bool> visited(n, false);
 
    for (int i = 0; i < n; i++) {
 
        // Skip this element if already processed
        if (visited[i] == true)
            continue;
 
        // Count frequency
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                visited[j] = true;
                count++;
            }
        }
        cout << arr[i] << " " << count << endl;
    }
}



//optimal approach         Time Complexity: O(N)  Space Complexity: O(n) unordered_map stores unique elements
void Frequency(int arr[], int n) 
{
    // Create an unordered_map to store frequencies
    // Key   -> element of array
    // Value -> frequency count
    unordered_map<int, int> map;
 
    // Traverse the array once
    for (int i = 0; i < n; i++)
        map[arr[i]]++;   // Increase frequency of arr[i]
 
    // Traverse through the hash map and print element + its frequency
    // x.first  -> key (array element)
    // x.second -> value (frequency)
    for (auto x : map)
        cout << x.first << " " << x.second << endl;
}

 
int main()
{
    int arr[] = {10,5,10,15,10,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    Frequency(arr, n);
    return 0;
}
            
