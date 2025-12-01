//https://leetcode.com/problems/move-zeroes/
// striver sheet


Input: 1 ,0 ,2 ,3 ,0 ,4 ,0 ,1
Output: 1 ,2 ,3 ,4 ,1 ,0 ,0 ,0
Explanation: All the zeros are moved to the end and non-negative integers are moved to front by maintaining order




// approacch 1
T.Complexity=0(n) && space complexity=0(n)

void moveZeroes(vector<int>& arr) {

    vector<int> ans;  // Stores all non-zero elements
    int zero = 0;     // Counts how many zeros are present

    // STEP 1: Separate non-zeros and count zeros
    for (int i = 0; i < arr.size(); i++) {

        // If element is NOT zero → store it
        if (arr[i] != 0) {
            ans.push_back(arr[i]);
        }
        else {
            zero++;  // Count zero
        }
    }

    // STEP 2: Add required number of zeros at the end
    for (int i = 0; i < zero; i++) {
        ans.push_back(0);
    }

    // (Optional) Copy ans back if needed
}



// broute force-> approach-2
T.Complexity=0(n) && space complexity=0(n)

    
void moveZeroes(vector<int>& nums) {

    int n = nums.size();
    vector<int> ans;   // Stores non-zero elements
    vector<int> ans2;  // Stores zero elements

    // STEP 1: Separate non-zeros and zeros into 2 arrays
    for (int i = 0; i < n; i++) {

        if (nums[i] != 0) {
            ans.push_back(nums[i]);   // non-zero
        }
        else {
            ans2.push_back(nums[i]);  // zero
        }
    }

    // STEP 2: Place all non-zeros back in nums[]
    for (int i = 0; i < ans.size(); i++) {
        nums[i] = ans[i];
    }

    // STEP 3: Place all zeros at the end
    int m = ans.size();
    for (int i = 0; i < ans2.size(); i++) {
        nums[m + i] = ans2[i];
    }
}




// otimize approazed
T.Complexity=0(n) && space complexity=0(1)
 void MoveZero(int arr[], int &n) {

    int left = 0;  // Pointer for placing next non-zero

    // right pointer moves normally
    for (int right = 0; right < n; right++) {

        // Whenever a non-zero is found
        if (arr[right] != 0) {

            // Swap it with element at 'left'
            swap(arr[left], arr[right]);

            // Move left to next position
            left++;
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
