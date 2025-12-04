https://leetcode.com/problems/maximum-product-subarray/description/
Input: Nums = [1,2,3,4,5,0]
Output: 120
Explanation: 
In the given array, 1×2×3×4×5 gives maximum product value.

Input: Nums = [1,2,-3,0,-4,-5]
Output: 20
Explanation: 
In the given array, (-4)×(-5) gives maximum product value.



  
// Broute Force -1    Time Complexity: O(N^2) && Space Complexity: O(1),
 
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



// optimal approach-1 // Time Complexity: O(N) && spaace=0(1)

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

