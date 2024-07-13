https://leetcode.com/problems/kth-missing-positive-number/

// striver sheet

//broute force
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // Iterate through each element in the array
        for(int i = 0; i < arr.size(); i++) {
            // If the current array element is less than or equal to k,
            // it means this element is one of the first k missing numbers.
            if(arr[i] <= k) {
                // Increment k to account for the found missing number
                k = k + 1;
            }
            // If the current array element is greater than k,
            // it means we have already found the first k missing numbers.
            else {
                break; // Exit the loop as further elements will be greater than k
            }
        }
        // Return the k-th missing number
        return k;
    }
};


// optimal approach
int findKthPositive(vector<int>& arr, int k) {
    // Initialize the start and end pointers for binary search
    int s = 0; 
    int e = arr.size() - 1;

    // Perform binary search
    while (s <= e) {
        // Calculate the middle index
        int mid = s + (e - s) / 2;
        
        // Calculate the number of missing elements until the current mid index
        // The number of missing elements up to arr[mid] is calculated as:
        // arr[mid] - (mid + 1)
        int missing = arr[mid] - (mid + 1);
        
        // If the number of missing elements is less than k,
        // move the start pointer to the right
        if (missing < k) {
            s = mid + 1;
        }
        // If the number of missing elements is greater than or equal to k,
        // move the end pointer to the left
        else {
            e = mid - 1;
        }
    }
    
    // After the binary search, 'e' will be the largest index
    // where the number of missing numbers is still less than 'k'.
    // Therefore, the k-th missing number can be calculated as:
    // k + e + 1
    return k + e + 1;
}
