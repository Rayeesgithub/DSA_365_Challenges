https://leetcode.com/problems/maximum-product-subarray/description/
// striver sheet

// Broute Force -1
int maxProductSubArray(vector<int>& arr) {
  int n=arr.size(); int maxi=INT_MIN;
  for(int i=0; i<n; i++){
    int pro=1;
    for(int j=i+1; j<n; j++){
    pro=pro*arr[j];
    maxi=max(maxi,pro);
    }
  }
  return maxi;
}



// optimal approach-1
int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int pre = 1, suff = 1; // Initialize two variables to keep track of prefix and suffix products.
    int ans = INT_MIN; // Initialize the answer with the smallest possible integer value.
    
    for (int i = 0; i < n; i++) { // Loop through the array.
        if (pre == 0) pre = 1; // If the prefix product becomes zero, reset it to 1.
        if (suff == 0) suff = 1; // If the suffix product becomes zero, reset it to 1.
        
        pre *= nums[i]; // Update the prefix product with the current element.
        suff *= nums[n - i - 1]; // Update the suffix product with the element from the end.
        
        ans = max(ans, max(pre, suff)); // Update the answer with the maximum of the current prefix and suffix products.
    }
    
    return ans; // Return the maximum product found.
}

// optimal approach-2
int maxProductSubArray(vector<int>& nums) {
    int prod1 = nums[0],prod2 = nums[0],result = nums[0];
    
    for(int i=1;i<nums.size();i++) {
        int temp = max({nums[i],prod1*nums[i],prod2*nums[i]});
        prod2 = min({nums[i],prod1*nums[i],prod2*nums[i]});
        prod1 = temp;
        
        result = max(result,prod1);
    }
    
    return result;
}
