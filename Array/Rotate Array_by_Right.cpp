//https://leetcode.com/problems/rotate-array/
// striver sheet

Input : nums = [1, 2, 3, 4, 5, 6, 7], k = 2, right
Output : [6, 7, 1, 2, 3, 4, 5]
Explanation : rotate 1 step to the right: [7, 1, 2, 3, 4, 5, 6]
rotate 2 steps to the right: [6, 7, 1, 2, 3, 4, 5] 
    

    
 // Approach 1: Split and merge method
    Time: O(n) & Space: O(n)


void rotate(vector<int>& nums, int k) {

    vector<int> ans(nums.size());   // new array to store rotated result

    // Step 1: Put the first (n-k) elements shifted to the right by k positions
    for(int i = 0; i < nums.size() - k; i++){
        ans[i + k] = nums[i];
        // Example: nums = [1,2,3,4,5], k = 2
        // ans[2] = 1, ans[3] = 2, ans[4] = 3
    }

    int j = 0;   // pointer for filling the front part of ans

    // Step 2: Put the last k elements to the beginning of ans
    for(int i = nums.size() - k; i < nums.size(); i++){
        ans[j] = nums[i];
        j++;
        // Example: put 4,5 → ans = [4,5,1,2,3]
    }

    // Step 3: Copy back to original array
    for(int i = 0; i < nums.size(); i++){
        nums[i] = ans[i];
    }
}




// apprach2
  Time: O(n) & Space: O(n)

void rotate(vector<int>& nums, int k) {

    int n = nums.size();
    vector<int> temp(n);   // temporary vector for rotated values

    for (int i = 0; i < n; i++) {
        // New index = (current index + k) % n
        temp[(i + k) % n] = nums[i];

        // Example: i=0, k=2 → newIndex = (0+2)%5 = 2
        // element at index 0 moves to index 2
    }

    // Copy back into original array
    for (int i = 0; i < n; i++) {
        nums[i] = temp[i];
    }
}




// apprach 3
  Time: O(n) & Space: O(1)
 // Approach 3: Reverse method (optimal)
vector<int> rotateArray(vector<int>& nums, int k, string direction) {

    int n = nums.size();

    // Edge case: empty or k=0 → no change
    if (n == 0 || k == 0) return nums;

    k = k % n;   // normalize k (important)

    if (direction == "right") {

        // RIGHT ROTATION STEPS:
        // Example: nums = [1,2,3,4,5], k=2 → result: [4,5,1,2,3]

        reverseArray(nums, 0, n-1);     // Step 1: reverse whole array
        // [5,4,3,2,1]

        reverseArray(nums, 0, k-1);     // Step 2: reverse first k
        // [4,5,3,2,1]

        reverseArray(nums, k, n-1);     // Step 3: reverse remaining part
        // [4,5,1,2,3]
    }

    else if (direction == "left") {

        // LEFT ROTATION STEPS:
        // Example: nums = [1,2,3,4,5], k=2 → result: [3,4,5,1,2]

        reverseArray(nums, 0, k-1);     // Step 1: reverse first k
        // [2,1,3,4,5]

        reverseArray(nums, k, n-1);     // Step 2: reverse n-k part
        // [2,1,5,4,3]

        reverseArray(nums, 0, n-1);     // Step 3: reverse whole
        // [3,4,5,1,2]
    }

    return nums;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    
    rotate(nums, k);
