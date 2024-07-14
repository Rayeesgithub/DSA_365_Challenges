https://leetcode.com/problems/search-a-2d-matrix/description/
// striver sheet


// broute force
 bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ans=false;
        for(int i=0;i<matrix.size();i++){
            for(int j=0; j<matrix[0].size();j++){
                if(matrix[i][j]==target){
            ans=true;
                }
            }
        }
        return ans;
    }


// optimal approach
class Solution {
public:
bool binarySearch(vector<int>& matrix,int target){
    int s=0; int e=matrix.size();
    while(s<=e){
        int mid=s+(e-s)/2;
        if(matrix[mid]==target){
            return true;
        }
        else if(matrix[mid]<target){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return false;
}
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        for(int i=0; i<row; i++){
            if(matrix[i][0]<=target && target<=matrix[i][col-1]){
                return binarySearch(matrix[i],target);
            }
        }
        return false;
    }
};

// optimal approach 2

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // Get the number of rows (n) and columns (m) in the matrix.
    int n = matrix.size();
    int m = matrix[0].size();

    // Initialize binary search bounds.
    int low = 0, high = n * m - 1;

    // Perform binary search.
    while (low <= high) {
        // Calculate the midpoint of the current search range.
        int mid = (low + high) / 2;
        
        // Determine the row and column corresponding to the midpoint.
        int row = mid / m;
        int col = mid % m;

        // Check if the target value is found at the current midpoint.
        if (matrix[row][col] == target) 
            return true;
        // If the target value is greater than the current midpoint value,
        // narrow the search to the upper half of the current range.
        else if (matrix[row][col] < target) 
            low = mid + 1;
        // If the target value is less than the current midpoint value,
        // narrow the search to the lower half of the current range.
        else 
            high = mid - 1;
    }

    // If the target value is not found, return false.
    return false;
}
