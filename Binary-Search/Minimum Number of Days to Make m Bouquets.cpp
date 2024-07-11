https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/
// striver sheet

// broute force
// Function to check if it is possible to make m bouquets in the given number of days.
bool possible(vector<int> &arr, int day, int m, int k) {
    int n = arr.size(); // Size of the array
    int cnt = 0; // Counter for consecutive flowers that can be picked
    int noOfB = 0; // Number of bouquets

    // Loop through each flower's bloom day
    for (int i = 0; i < n; i++) {
        // If the flower blooms on or before the given day, increment the counter
        if (arr[i] <= day) {
            cnt++;
        } else {
            // If a flower blooms after the given day, calculate bouquets from the counter
            noOfB += (cnt / k);
            cnt = 0; // Reset the counter
        }
    }

    // Add the bouquets from the last batch of flowers if any
    noOfB += (cnt / k);

    // Return true if the number of bouquets is at least m
    return noOfB >= m;
}

// Function to find the minimum number of days to make m bouquets.
int minDays(vector<int>& bloomDay, int m, int k) {
    // If it's not possible to make m bouquets, return -1
    if (m * k > bloomDay.size()) {
        return -1;
    }

    // Initialize the minimum and maximum bloom days
    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < bloomDay.size(); i++) {
        mini = min(mini, bloomDay[i]);
        maxi = max(maxi, bloomDay[i]);
    }

    // Brute force approach: check each day from the minimum to the maximum bloom day
    for (int i = mini; i <= maxi; i++) {
        if (possible(bloomDay, i, m, k)) {
            return i; // Return the day when it is possible to make m bouquets
        }
    }

    // If no valid day is found, return -1
    return -1;
}


// optimal approach

class Solution {
public:
    // Function to check if it's possible to make m bouquets in 'day' days
    bool possible(vector<int> &arr, int day, int m, int k) {
        int n = arr.size(); // Size of the array
        int cnt = 0; // Counter for consecutive flowers that can be picked
        int noOfB = 0; // Number of bouquets

        // Loop through each flower's bloom day
        for (int i = 0; i < n; i++) {
            // If the flower blooms on or before the given day, increment the counter
            if (arr[i] <= day) {
                cnt++;
            } else {
                // If a flower blooms after the given day, calculate bouquets from the counter
                noOfB += (cnt / k);
                cnt = 0; // Reset the counter
            }
        }

        // Add the bouquets from the last batch of flowers if any
        noOfB += (cnt / k);

        // Return true if the number of bouquets is at least m
        return noOfB >= m;
    }
    
    // Function to find the minimum number of days to make m bouquets
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m * 1ll * k * 1ll; // Using long long to avoid overflow
        if (val > bloomDay.size()) { // If it's not possible to make m bouquets
            return -1;
        }
        
        // Initialize the minimum and maximum bloom days
        int mini = INT_MAX, maxi = INT_MIN;
        for (int i = 0; i < bloomDay.size(); i++) {
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }

        // Binary search for the minimum possible day
        int s = mini, e = maxi;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (possible(bloomDay, mid, m, k)) {
                e = mid - 1; // If it's possible, try for a smaller day
            } else {
                s = mid + 1; // If not possible, try for a larger day
            }
        }

        // Return the smallest day found where it's possible to make m bouquets
        return s;
    } 
};
