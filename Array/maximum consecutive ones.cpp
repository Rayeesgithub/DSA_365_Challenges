//https://leetcode.com/problems/max-consecutive-ones/
// striver sheet
//Time Complexity: O(N) space-com=0(1)
int findMaxConsecutiveOnes(vector<int>& nums) {
    int maxi = 0;   // Initialize maxi to store the maximum count of consecutive 1s found
    int count = 0;  // Initialize count to store the current count of consecutive 1s
    int n = nums.size();  
    for (int i = 0; i < n; i++) {
        if (nums[i] == 1) { 
            count++;         // Increment the count of consecutive 1s
        } else {             //else if(nums[i]==0 )         // If the current element is 0
            count = 0;       // Reset the count to 0
        }
        maxi = max(maxi, count);  // Update maxi if the current count is greater than maxi
    }
    
    return maxi;  // Return the maximum count of consecutive 1s found
}

int main() {
    vector<int> nums = {1, 1, 0, 1, 1, 1};  // Example input vector
    cout << "Max consecutive ones: " << findMaxConsecutiveOnes(nums) << endl;  // Call the function and print the result

    return 0;
}
