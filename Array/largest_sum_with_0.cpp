//https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum
//striver sheet 

//approach1-> \
#include <vector>
#include <unordered_map>
using namespace std;

int maxLen(vector<int>& arr, int n) {
    unordered_map<int, int> prefixSumMap; // map to store prefix sum and its index
    int maxi = 0; // to store the maximum length of subarray
    int sum = 0; // to store the current prefix sum

    for (int i = 0; i < n; i++) {
        sum += arr[i]; // calculate the prefix sum
        
        if (sum == 0) {
            // if the sum is zero, the subarray from 0 to i has sum zero
            maxi = i + 1;
        } else {
            // if the sum is found in the map, it means the subarray from the next index to i has sum zero
            if (prefixSumMap.find(sum) != prefixSumMap.end()) {
                maxi = max(maxi, i - prefixSumMap[sum]);
            } else {
                // if the sum is not found, store it in the map
                prefixSumMap[sum] = i;
            }
        }
    }

    return maxi;
}
