//https://leetcode.com/problems/move-zeroes/
// striver sheet
#include <iostream>
#include <vector>
using namespace std;
// approacch 1 T.Complexity=0(n) && space complexity=0(n)
void moveZeroes(vector<int>& nums) {
    int n = nums.size();  // Get the size of the input vector
 // Create a temporary vector to store non-zero elements
    vector<int> temp;
  // Add non-zero elements to the temporary vector
    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            temp.push_back(nums[i]);
        }
    }
 // Add zero elements to the temporary vector
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            temp.push_back(nums[i]);
        }
    }
// Copy elements from the temporary vector back to the original vector
    for (int i = 0; i < n; i++) {
        nums[i] = temp[i];
    }


  
// second approach-> using two pointer T.Complexity=0(n) && space complexity=0(1)
int j=-1;
for(int i=0; i<n; i++){
if(nums[i]==0) {
    j=i;
    break;
}
}
for(int i=j+1; i<n; i++){
    if(nums[i]!=nums[j]){
        swap(nums[j],nums[i]);
        j++;
    }
}
}
int main() {
    vector<int> nums = { 9 ,0 ,12 ,8 ,0 ,4 ,0 ,5,0};

    moveZeroes(nums);

    // Print the modified vector
    for (int i : nums) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
