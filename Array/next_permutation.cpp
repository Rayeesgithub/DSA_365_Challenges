//https://leetcode.com/problems/next-permutation/
//striver sheet


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // // stl Approach O(nlogn)
        // next_permutation(nums.begin(),nums.end());
        // nums;
      //2nd Approach
      int index=-1;
      int n=nums.size();
    // Traverse the array from second last element to the first.
for(int i = n - 2; i >= 0; i--) {
    // Check if the current element is less than the next element.
    if(nums[i] < nums[i + 1]) {
        index = i; // Store the index of the element.
        break;
    }}// If no such index found (i.e., the array is in descending order),
// reverse the array to get the smallest permutation and return.
if(index == -1) {
    reverse(nums.begin(), nums.end());
    return;}
// Find the rightmost element greater than the element at index.
for(int i = n - 1; i > index; i--) {
    if(nums[i] > nums[index]) {
        swap(nums[i], nums[index]); // Swap the two elements.
        break; }}
// Reverse the subarray from index+1 to the end of the array.
       reverse(nums.begin()+index+1,nums.end());
    }
};




class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int i = n - 2;

    // Step 1: Find first decreasing element from right
    while (i >= 0 && nums[i] >= nums[i + 1]) i--;

    if (i >= 0) {
        // Step 2: Find element just larger than nums[i]
        int j = n - 1;
        while (nums[j] <= nums[i]) j--;
        swap(nums[i], nums[j]);
    }

    // Step 3: Reverse the right part
    reverse(nums.begin() + i + 1, nums.end());
}
};
