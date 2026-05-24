Input: A = [4, 2, 2, 6, 4] , k = 6
Output: 4
Explanation: The subarrays having XOR of their elements as 6 are  [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]


// Broute force
  // Time Complexity: O(N^2),

  
   int countSubarraysXOR(vector<int>& A, int B) {
        // Initialize count of valid subarrays
        int count = 0;
        // Traverse all starting points
        for (int i = 0; i < A.size(); i++) {
            // Maintain xor of current subarray
            int xorVal = 0;
            // Extend subarray till end
            for (int j = i; j < A.size(); j++) {
                // Update xor
                xorVal ^= A[j];
                // If xor equals B, increment count
                if (xorVal == B) {
                    count++;
                }
            }
        }
        return count;
    }



  // optimal 
  #include <vector>
#include <unordered_map>
using namespace std;

int subarraysWithXOR_K(vector<int>& A, int k) {
    int n = A.size();
    unordered_map<int, int> xor_map;
    
    // Base Case: A prefix XOR of 0 has occurred exactly 1 time
    // (handles subarrays that satisfy the condition starting directly from index 0)
    xor_map[0] = 1;
    
    int current_xor = 0;
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        // Update cumulative bitwise XOR
        current_xor = current_xor ^ A[i];
        
        // Calculate the target prefix XOR we need to find and remove
        int target = current_xor ^ k;
        
        // If that target prefix XOR has been seen before, add its frequency to our count
        if (xor_map.find(target) != xor_map.end()) {
            count += xor_map[target];
        }
        
        // Record the current prefix XOR into the map
        xor_map[current_xor]++;
    }
    
    return count;
}
