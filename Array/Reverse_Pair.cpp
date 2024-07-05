https://leetcode.com/problems/reverse-pairs/
// striver


//broute force
int reversePairs(vector<int>& nums) {
    long long count = 0; // Initialize the count of reverse pairs
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            // Check if nums[i] is greater than twice nums[j]
            if (nums[i] > 2 * (long long) nums[j]) count++;
        }
    }
    return count; // Return the count of reverse pairs
}


// optimal approach

void merge(vector<int>& nums, int low, int mid, int high, int& reversePairsCount) {
        int j = mid + 1; // Initialize pointer for the second half
        for (int i = low; i <= mid; i++) {
            // Count reverse pairs
            while (j <= high && nums[i] > 2 * (long long) nums[j]) {
                j++;
            }
            reversePairsCount += j - (mid + 1);
        }
        
        int size = high - low + 1;
        vector<int> temp(size, 0); // Temporary vector for merging
        int left = low, right = mid + 1, k = 0;
        
        // Merge the two sorted halves
        while (left <= mid && right <= high) {
            if (nums[left] < nums[right]) {
                temp[k++] = nums[left++];
            } else {
                temp[k++] = nums[right++];
            }
        }
        while (left <= mid) {
            temp[k++] = nums[left++];
        }
        while (right <= high) {
            temp[k++] = nums[right++];
        }
        
        // Copy the merged array back to the original array
        int m = 0;
        for (int i = low; i <= high; i++) {
            nums[i] = temp[m++];
        }
    }

    // Function to perform merge sort and count reverse pairs
    void mergeSort(vector<int>& nums, int low, int high, int& reversePairsCount) {
        if (low >= high) {
            return; // Base case: single element
        }
        int mid = (low + high) >> 1;
        mergeSort(nums, low, mid, reversePairsCount); // Sort the first half
        mergeSort(nums, mid + 1, high, reversePairsCount); // Sort the second half
        merge(nums, low, mid, high, reversePairsCount); // Merge the two halves and count reverse pairs
    }

    // Function to count reverse pairs using merge sort
    int reversePairs(vector<int>& nums) {
        int reversePairsCount = 0; // Initialize the count of reverse pairs
        mergeSort(nums, 0, nums.size() - 1, reversePairsCount); // Perform merge sort and count reverse pairs
        return reversePairsCount; // Return the count of reverse pairs
    }
};
