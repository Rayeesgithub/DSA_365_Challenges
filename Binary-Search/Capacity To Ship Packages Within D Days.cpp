https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/
//striver sheet

// broute Force
class Solution {
public:
    // Function to calculate the number of days required to ship all packages with the given capacity
    int findDays(vector<int>& weights, int cap) {
        int days = 1;
        int load = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (load + weights[i] > cap) {
                days += 1; // Move to next day
                load = weights[i]; // Load the weight for the new day
            } else {
                load += weights[i]; // Load the weight on the same day
            }
        }
        return days;
    }

    // Function to find the minimum capacity to ship packages within the given days
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi = INT_MIN;
        long long sum = 0;
        for (int i = 0; i < weights.size(); i++) {
            maxi = max(maxi, weights[i]);
            sum += weights[i];
        }

        for (int i = maxi; i <= sum; i++) { // Loop should include sum
            int daysReq = findDays(weights, i);
            if (daysReq <= days) {
                return i; // Return the minimum capacity
            }
        }

        return -1; // Return -1 if no valid capacity is found
    }
};                                                 



// optimal approach
class Solution {
public:
    // Function to calculate the number of days required to ship all packages with the given capacity
    int findDays(vector<int>& weights, int cap) {
        int days = 1;  // Start with the first day
        int load = 0;  // Current load for the day
        for (int i = 0; i < weights.size(); i++) {
            // Check if adding the current package exceeds the capacity
            if (load + weights[i] > cap) {
                days += 1;      // Move to the next day
                load = weights[i]; // Load the weight for the new day
            } else {
                load += weights[i]; // Load the weight on the same day
            }
        }
        return days; // Return the total number of days required
    }

    // Function to find the minimum capacity to ship packages within the given days
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi = INT_MIN;  // Initialize the maximum element to minimum integer value
        long long sum = 0;   // Initialize the sum of weights
        for (int i = 0; i < weights.size(); i++) {
            maxi = max(maxi, weights[i]); // Find the maximum weight
            sum += weights[i];            // Calculate the total sum of weights
        } 

        int s = maxi;  // The minimum capacity should be at least the maximum weight
        int e = sum;   // The maximum capacity can be the total sum of weights
        while (s <= e) {
            int mid = s + (e - s) / 2; // Calculate the mid value to check
            int daysReq = findDays(weights, mid); // Find the days required with mid capacity
            if (daysReq <= days) {
                e = mid - 1; // Try for a smaller capacity if it fits within the given days
            } else {
                s = mid + 1; // Try for a larger capacity if it doesn't fit within the given days
            }
        }
        return s; // Return the smallest capacity that can ship the packages within the given days
    }
};
