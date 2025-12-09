Input : nums1 = [-5, -2, 4, 5, 0, 0, 0], nums2 = [-3, 1, 8]
Output : [-5, -3, -2, 1, 4, 5, 8]
Explanation : The merged array is: [-5, -3, -2, 1, 4, 5, 8], where [-5, -2, 4, 5] are from nums1 and [-3, 1, 8] are from nums2





//approach1->Borute force
void Merg(vector<int>&arr1,vector<int>&arr2){
     int n1=arr1.size(); int n2=arr2.size();
     vector<int>ans;
     for(int i=0; i<n1; i++){
        ans.push_back(arr1[i]);

     }
     for(int i=0; i<n2; i++){
        ans.push_back(arr2[i]);
     }

     sort(ans.begin(),ans.end());
     for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
     }
  }

// approach2-> Optimal Approach
T.C-0(n+m) S.C->0(1)
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1;        // pointer for nums1 last element
    int j = n - 1;        // pointer for nums2 last element
    int k = m + n - 1;    // pointer for nums1 final position

    // Compare from the end and place the larger element at the end of nums1
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    // If nums2 still has elements left, copy them
    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}
