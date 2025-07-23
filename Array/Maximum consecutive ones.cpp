//https://leetcode.com/problems/max-consecutive-ones/
Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.




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


//anoter approach
  int count=0; vector<int>ans;
    for(int i=0; i<n; i++){
        if(arr[i]==1){
            count++;
        }
        else if(arr[i]!=1){
            ans.push_back(count);
            count=0;
        }
    }
    int maxi=INT_MIN;
   for(int i=0;i<ans.size();i++){
    maxi=max(maxi,ans[i]);
   }
   cout<<"Maximum Number of 1's:"<<maxi;
int main() {
    vector<int> nums = {1, 1, 0, 1, 1, 1};  // Example input vector
    cout << "Max consecutive ones: " << findMaxConsecutiveOnes(nums) << endl;  // Call the function and print the result

    return 0;
}




Input: arr[] = [0, 0, 1, 0, 1, 0]
Output: 2
Explanation: The maximum number of consecutive 0’s in the array is 2 from index 0-1.

    class Solution {
  public:
  
   int maxConsecBits(vector<int> &arr) {
    int count0 = 0, count1 = 0;
    int maxi0 = 0, maxi1 = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 1) {
            count1++;
            maxi1 = max(maxi1, count1);
            count0 = 0;  // Reset count0 since we found 1
        } else {
            count0++;
            maxi0 = max(maxi0, count0);
            count1 = 0;  // Reset count1 since we found 0
        }
    }

    return max(maxi0, maxi1);
}

};
