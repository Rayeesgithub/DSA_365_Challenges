//https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/
striver

// Function to check if mid^n is equal to, less than, or greater than m
int func(int mid, int n, int m) {
    long long ans = 1; // Initialize ans to 1
    for (int i = 1; i <= n; i++) { // Loop to calculate mid^n
        ans = ans * mid; // Multiply ans by mid in each iteration
        if (ans > m) return 2; // If ans exceeds m, return 2
    }
    if (ans == m) return 1; // If ans is equal to m, return 1
    return 0; // If ans is less than m, return 0
}

// Function to find the nth root of m
int NthRoot(int n, int m) {
    // Initialize low and high pointers for binary search
    int low = 1, high = m;
    while (low <= high) { // Loop until low is less than or equal to high
        int mid = (low + high) / 2; // Calculate mid
        int midN = func(mid, n, m); // Check the result of mid^n compared to m
        if (midN == 1) { // If mid^n is equal to m
            return mid; // Return mid as the nth root of m
        }
        else if (midN == 0) { // If mid^n is less than m
            low = mid + 1; // Move the low pointer to mid + 1
        }
        else { // If mid^n is greater than m
            high = mid - 1; // Move the high pointer to mid - 1
        }
    }
    return -1; // If no valid nth root is found, return -1
}
