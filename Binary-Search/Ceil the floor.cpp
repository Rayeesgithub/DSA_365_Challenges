https://www.geeksforgeeks.org/problems/ceil-the-floor2802/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=ceil-the-floor
// striver


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // Initialize variables to hold the maximum floor and minimum ceiling found so far
    int maxi = INT_MIN; 
    int mini = INT_MAX; 
     // Iterate through the array to find the floor and ceiling
    for(int i = 0; i < n; i++) {
        // Finding the floor: Largest element <= x
        if(arr[i] <= x && arr[i] > maxi) {
            maxi = arr[i]; // Update maxi if current element is a better candidate for floor
        }
        
        // Finding the ceiling: Smallest element >= x
        if(arr[i] >= x && arr[i] < mini) {
            mini = arr[i]; // Update mini if current element is a better candidate for ceiling
        }
    }
    
    // Handle edge cases where no floor or ceiling exists
    if(maxi == INT_MIN) {
        maxi = -1; // If no valid floor found, set maxi to -1
    }
    if(mini == INT_MAX) {
        mini = -1; // If no valid ceiling found, set mini to -1
    }
    
    // Return the pair of floor and ceiling
    return {maxi, mini};
}
