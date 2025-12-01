//https://leetcode.com/problems/missing-number/
Example 1:
Input Format: N = 5, array[] = {1,2,4,5}
Result: 3
Explanation: In the given array, number 3 is missing. So, 3 is the answer

//broute force
Time= O(N logN) && space=O(1)
int missingNumber(vector<int>& nums) {

    // Sort the array to bring numbers in order
    // Sorting takes O(N logN)
    sort(nums.begin(), nums.end());

    int ans = -1;

    // If array doesn't start with 0 → missing number is 0
    if (nums[0] != 0) return 0;

    // Check for the first missing number by checking gaps
    for (int i = 0; i < nums.size() - 1; i++) {
        // If next number is not equal to current+1 → gap found
        if (nums[i + 1] != nums[i] + 1) {
            ans = nums[i] + 1;
            break;
        }
    }

    // If no gap found → missing number is (last element + 1)
    if (ans == -1) {
        ans = nums[nums.size() - 1] + 1;
    }

    return ans;
}




// approach2 
Time Complexity: O(N) && Space Complexity: O(1)

         
int missingNumber(vector<int>& nums) {

    int xor1 = 0, xor2 = 0;
    int n = nums.size();

    // XOR of all numbers from 0 to n
    // Example: 0 ^ 1 ^ 2 ^ 3 ... ^ n
    for (int i = 0; i <= n; i++) {
        xor1 = xor1 ^ i;
    }

    // XOR of all elements in array
    for (int i = 0; i < n; i++) {
        xor2 = xor2 ^ nums[i];
    }

    // XOR of xor1 and xor2 gives the missing number
    // Because pairs cancel each other
    return xor1 ^ xor2;
}



   //approach-2
    //second approach Time Complexity: O(N) && Space Complexity: O(1) 
int missingNumber(vector<int>& nums) {

    int n = nums.size();

    // Total sum of numbers from 0 to n
    // Formula: n*(n+1)/2
    int totalsum = n * (n + 1) / 2;

    int sum = 0;

    // Sum all elements in array
    for (int i = 0; i < n; i++) {
        sum = sum + nums[i];
    }

    // Missing number = expected sum - current sum
    return totalsum - sum;
}
