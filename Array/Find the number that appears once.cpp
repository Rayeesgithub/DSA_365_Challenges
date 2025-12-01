//https://leetcode.com/problems/single-number/




Example 2:
Input Format: arr[] = {4,1,2,1,2}
Result: 4
Explanation: In this array, only element 4 appear once and the other elements appear twice. So, 4 is the answer.


// approach1 
Time=0(n^2) space=(1)

      int getSingleElement(vector<int>& arr) {
    int n = arr.size();

    // Check each element one by one
    for (int i = 0; i < n; i++) {

        int num = arr[i];   // Pick the current element
        int cnt = 0;        // Counter to count its occurrences

        // Count how many times 'num' appears in the whole array
        for (int j = 0; j < n; j++) {
            if (arr[j] == num) 
                cnt++;      // Found a match
        }

        // If this number appears exactly once → this is the answer
        if (cnt == 1) {
            return num;
        }
    }

    return -1;  // (never reaches here if input is valid)
}

};

        
approach2-> using xor approach
Time-com=0(n) && space-com=(1)

int singleNumber(vector<int>& nums) {

    int ans = 0; 
    int n = nums.size();

    // XOR all numbers
    for (int i = 0; i < n; i++) {
        ans = ans ^ nums[i];
    }

    // Remaining number is the unique one
    return ans;
}


Example (nums = [2, 2, 5, 4, 4]
ans = 0
ans = 0 ^ 2 = 2
ans = 2 ^ 2 = 0   (pair canceled)
ans = 0 ^ 5 = 5
ans = 5 ^ 4 = 1
ans = 1 ^ 4 = 5   (pair canceled → 5 remains)



// approach3-> using maping Time-com=0(n) && space-com=(n)
       int singleNumber(vector<int>& nums) {

    unordered_map<int,int> mp; // to store frequency
    int n = nums.size();
    int ans = -1;

    // Count frequency of each element
    for (int i = 0; i < n; i++) {
        mp[nums[i]]++;
    }

    // Find the element with count = 1
    for (auto it : mp) {
        if (it.second == 1) {
            ans = it.first;
        }
    }

    return ans;
}


🔍 Example (nums = [2, 2, 5, 4, 4])

Map becomes:

2 → 2 times
5 → 1 time   ← UNIQUE
4 → 2 times
