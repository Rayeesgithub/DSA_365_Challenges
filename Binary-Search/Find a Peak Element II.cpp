https://leetcode.com/problems/find-a-peak-element-ii/description/
striver sheet

// broute force
 vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int maxi=INT_MIN;
       vector<int>index(2,-1);
       
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size();j++){
                if(mat[i][j]>maxi){
                    maxi=mat[i][j];
                   index[0]=i;
                   index[1]=j;
                }
            }
        }
        return index;
    }

// optimal approach
