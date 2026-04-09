Example 1:  
Input: nums = [100, 4, 200, 1, 3, 2]  
Output: 4  
Explanation: The longest sequence of consecutive elements in the array is [1, 2, 3, 4], which has a length of 4. This sequence can be formed regardless of the initial order of the elements in the array.

Example 2:  
Input: nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]  
Output: 9  


  

// Time = O(n log n) because of sorting
// This approach finds the Longest Consecutive Sequence

void solve(vector<int>& arr){
    int n = arr.size();
    if(n == 0) return;

    sort(arr.begin(), arr.end());

    int longest = 1;
    int count = 1;

    for(int i = 1; i < n; i++){

        if(arr[i] == arr[i-1]){
            continue;   // skip duplicates
        }
        else if(arr[i] == arr[i-1] + 1){
            count++;    // consecutive
        }
        else{
            count = 1;  // reset
        }

        longest = max(longest, count);
    }

    cout << longest;
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
