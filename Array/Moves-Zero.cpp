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


// otimize approazed
// PATTERN-> Same Direction Template(Two Pointer)

// T.Complexity=0(n) && space complexity=0(1)
void moveZeroes(vector<int>& arr) {
    int slow = 0;
    
    for(int fast = 0; fast < arr.size(); fast++) {
        if(arr[fast] != 0) {
            swap(arr[slow], arr[fast]);
            slow++;
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
