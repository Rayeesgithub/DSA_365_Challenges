Example 1:  
Input: nums = [100, 4, 200, 1, 3, 2]  
Output: 4  
Explanation: The longest sequence of consecutive elements in the array is [1, 2, 3, 4], which has a length of 4. This sequence can be formed regardless of the initial order of the elements in the array.

Example 2:  
Input: nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]  
Output: 9  


  

// Time = O(n log n) because of sorting
// This approach finds the Longest Consecutive Sequence

int LongConsecutive(int arr[], int n) {

    // Step 1: Sort the array so consecutive numbers come together
    sort(arr, arr + n);

    int count = 0;          // counts current consecutive streak
    int maxLength = 1;      // stores the best (maximum) streak
    int lastSmaller = INT_MIN;  // keeps last valid consecutive element

    for (int i = 0; i < n; i++) {

        // Case 1: Current element continues the chain
        // Example: lastSmaller = 4 → arr[i] = 5 (5 - 1 == 4)
        if (arr[i] - 1 == lastSmaller) {
            count++;               
            lastSmaller = arr[i];  
        }

        // Case 2: Duplicate value → ignore it  
        // Example: arr = [1,1,2,3] → when arr[i] == lastSmaller → skip
        else if (arr[i] != lastSmaller) {
            count = 1;              // restart new sequence
            lastSmaller = arr[i];
        }

        // Update maximum sequence length
        maxLength = max(maxLength, count);
    }

    return maxLength;
}



// optimized version
// Optimal Approach: O(n) Time & O(n) Space
// Uses HashSet to find longest consecutive sequence

int LongConsecutiveOptimized(vector<int>& nums) {

    unordered_set<int> st;

    // Insert all elements into set
    for (int num : nums) {
        st.insert(num);
    }

    int longest = 1;

    // Check each element
    for (int num : st) {

        // If (num - 1) is NOT in the set → num is START of sequence
        // Example: For sequence [4,5,6], only 4 will satisfy this
        if (st.find(num - 1) == st.end()) {

            int currentNum = num;
            int count = 1;

            // Count consecutive numbers forward (num, num+1, num+2 ...)
            while (st.find(currentNum + 1) != st.end()) {
                currentNum++;
                count++;
            }

            longest = max(longest, count);
        }
    }

    return longest;
}

int main(){
  int n=6;
  int arr[n]={100, 200, 1, 3, 2, 4};
  int ans=LongConsegutive(arr,n);
  cout<<"Longes Consegutive Sequence is:"<<ans;
}
