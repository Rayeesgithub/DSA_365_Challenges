Input : nums = [1, 2, 3, 4, 5, 6, 7], k = 2, right
Output : [6, 7, 1, 2, 3, 4, 5]
Explanation : rotate 1 step to the right: [7, 1, 2, 3, 4, 5, 6]
rotate 2 steps to the right: [6, 7, 1, 2, 3, 4, 5] 


  // Approach1
void solve(vector<int>& arr, int k){
    int n = arr.size();
    k = k % n;

    vector<int> temp;

    // store last k elements
    for(int i = n - k; i < n; i++){
        temp.push_back(arr[i]);
    }

    // shift remaining elements right
    for(int i = n - k - 1; i >= 0; i--){
        arr[i + k] = arr[i];
    }

    // place temp elements at beginning
    for(int i = 0; i < k; i++){
        arr[i] = temp[i];
    }
}



// approach2

void solve(vector<int>& arr, int k){
    int n = arr.size();
    k = k % n;

    // Step 1: reverse whole array
    reverse(arr.begin(), arr.end());

    // Step 2: reverse first k elements
    reverse(arr.begin(), arr.begin() + k);

    // Step 3: reverse remaining elements
    reverse(arr.begin() + k, arr.end());
}
