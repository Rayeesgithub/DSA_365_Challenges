Input:
 nums = [2, 3, -1, 8, 4]  
Output:
 3  
Explanation:
  
The sum of the numbers before index 3 is: 2 + 3 + (-1) = 4  
The sum of the numbers after index 3 is: 4 = 4  
Therefore, the output is index 3.


// approach1
int findEquilibriumIdx(int nums[], int n) {
    // Loop through each element of the array to check if it's the equilibrium index
    for (int i = 0; i < n; i++) {
        int leftSum = 0, rightSum = 0;

        // Calculate the sum of elements on the left side of the current index
        for (int j = 0; j < i; j++) {
            leftSum += nums[j];
        }

        // Calculate the sum of elements on the right side of the current index
        for (int j = i + 1; j < n; j++) {
            rightSum += nums[j];
        }

        // Check if the left sum equals the right sum
        if (leftSum == rightSum) {
            return i;  // Return the equilibrium index
        }
    }
    return -1;  // Return -1 if no equilibrium index is found
}


///2nd  approach
int findEquilibriumIdx(int nums[], int n) {
    // Calculate the total sum of the array
    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        totalSum += nums[i];
    }

    // Initialize left and right sums
    int leftSum = 0, rightSum = totalSum;

    // Loop through the array to check if any index is the equilibrium index
    for (int i = 0; i < n; i++) {
        rightSum -= nums[i];  // Subtract the current element from right sum

        // Check if left sum is equal to right sum
        if (leftSum == rightSum) {
            return i;  // Return the equilibrium index
        }

        leftSum += nums[i];  // Add the current element to left sum
    }

    return -1;  // Return -1 if no equilibrium index is found
}
