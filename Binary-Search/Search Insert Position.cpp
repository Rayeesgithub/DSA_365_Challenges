https://leetcode.com/problems/search-insert-position/description/
//striver sheet

int searchInsert(vector<int>& nums, int target) {
    int s = 0; 
    int e = nums.size() - 1;

    // Perform binary search
    while(s <= e) {
        int mid = s + (e - s) / 2;

        // If target is found, return the index
        if(nums[mid] == target) {
            return mid;
        }
        // If target is greater than mid element, search in the right half
        else if(nums[mid] < target) {
            s = mid + 1;
        }
        // If target is smaller than mid element, search in the left half
        else if(nums[mid] > target) {
            e = mid - 1;
        }
    }

    // If target is not found, return the index where the start index it should be inserted
    return s;
}
