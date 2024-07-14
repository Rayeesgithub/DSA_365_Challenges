https://leetcode.com/problems/search-a-2d-matrix-ii/description/

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
   bool search(vector<int>matrix,int target){
        int s=0; int e=matrix.size()-1;
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
        int n=matrix.size();
        for(int i=0; i<n; i++){
            if(search(matrix[i],target)){
                return true;
            }
        }
        return false;
    }
