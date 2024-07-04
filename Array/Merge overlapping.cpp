https://leetcode.com/problems/merge-intervals/
// striver sheet
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size(); // Size of the intervals array
        
        // Brute force approach
        sort(intervals.begin(), intervals.end()); // Sort intervals based on start times
       
        vector<vector<int>> ans; // Vector to store the merged intervals

        // Iterate through each interval
        for (int i = 0; i < n; i++) {
            int start = intervals[i][0]; // Start time of the current interval
            int end = intervals[i][1]; // End time of the current interval

            // Skip intervals that are already merged
            if (!ans.empty() && end <= ans.back()[1]) continue;

            // Merge overlapping intervals
            for (int j = i + 1; j < n; j++) {
                if (intervals[j][0] <= end) {
                    // If intervals overlap, update the end time
                    end = max(end, intervals[j][1]);
                } else {
                    // If intervals do not overlap, break the loop
                    break;
                }
            }

            // Add the merged interval to the result
            ans.push_back({start, end});
        }

        // Optimal approach
        sort(intervals.begin(), intervals.end()); // Sort intervals again for optimal approach

        vector<vector<int>> ans_opt; // Vector to store the merged intervals in optimal approach

        // Iterate through each interval
        for (int i = 0; i < n; i++) {
            // If the result is empty or the current interval does not overlap with the last interval in the result
            if (ans_opt.empty() || intervals[i][0] > ans_opt.back()[1]) {
                // Add the current interval to the result
                ans_opt.push_back(intervals[i]);
            } else {
                // If the current interval overlaps with the last interval, merge them by updating the end time
                ans_opt.back()[1] = max(ans_opt.back()[1], intervals[i][1]);
            }
        }

        return ans_opt; // Return the result of the optimal approach
    }
};
