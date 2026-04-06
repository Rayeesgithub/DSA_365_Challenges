Input : nums = [1, 2, 3, 4, 5, 6], k=2, left
Output : [3, 4, 5, 6, 1, 2]
Explanation :rotate 1 step to the left: [2, 3, 4, 5, 6, 1]
rotate 2 steps to the left: [3, 4, 5, 6, 1, 2]

// approach-1
  vector<int> rotateLeft(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> ans(n);

    // Copy elements from k to end → starting from index 0
    int index = 0;
    for (int i = k; i < n; i++) {
        ans[index++] = nums[i];
    }

    // Copy first k elements at the end
    for (int i = 0; i < k; i++) {
        ans[index++] = nums[i];
    }

    return ans;
}


// another approach
void solve(vector<int>& arr, int k){
    int n = arr.size();
    k = k % n;

    // Step 1: reverse first k elements
    reverse(arr.begin(), arr.begin() + k);

    // Step 2: reverse remaining elements
    reverse(arr.begin() + k, arr.end());

    // Step 3: reverse whole array
    reverse(arr.begin(), arr.end());
}

⏱️ Complexity
Time: O(n)
Space: O(1) ✅ (optimal)




//apprach-2
vector<int> rotateLeft(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> temp(n);

    for (int i = 0; i < n; i++) {
        temp[(i - k + n) % n] = nums[i];   // for right rotate-> temp[(i+k)%n]=nums[i]
    }

    return temp;
}
