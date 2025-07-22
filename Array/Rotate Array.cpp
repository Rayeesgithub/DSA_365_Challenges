//https://leetcode.com/problems/rotate-array/
// striver sheet

Input: arr[] = [1, 2, 3, 4, 5, 6], k = 2
Output: [5, 6, 1, 2, 3, 4]
Explanation: Rotating the array 2 times in clockwise gives the array [5, 6, 1, 2, 3, 4].
    
    
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> temp(n); // Create a temporary vector to store the rotated elements
 // Loop through the original vector
    for (int i = 0; i < n; i++) {
        // Calculate the new position for each element after rotation
        // (i + k) % n ensures that the index wraps around the array
        temp[(i + k) % n] = nums[i];
    }

    // Copy the rotated elements from the temporary vector back to the original vector
    for (int i = 0; i < n; i++) {
        nums[i] = temp[i];
    }
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    
    rotate(nums, k);
