//gfg
// striver sheet

// broute force 1
 int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        vector<int>ans;
        for(int i=0; i<n; i++){
            ans.push_back(arr1[i]);
        }
        for(int i=0; i<m; i++){
            ans.push_back(arr2[i]);
        }
        sort(ans.begin(),ans.end());
        int  res=0;
        for(int i=0; i<ans.size(); i++){
            res=ans[k-1];
        }
        
        return res;
    }
