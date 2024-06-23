//https://leetcode.com/problems/longest-consecutive-sequence/
// striver sheet

int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0; // If the array is empty, return 0

        sort(nums.begin(), nums.end()); // Sort the array

        int longestStreak = 1;
        int currentStreak = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) { // Ignore duplicates
                if (nums[i] == nums[i - 1] + 1) {
                    // Increment the current streak if the current element is consecutive
                    currentStreak++;
                } else {
                    // Update the longest streak and reset current streak
                    longestStreak = max(longestStreak, currentStreak);
                    currentStreak = 1;
                }
            }
        }
        // The final comparison for the last streak
        return max(longestStreak, currentStreak);
    }
