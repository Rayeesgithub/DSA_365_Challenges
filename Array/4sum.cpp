https://leetcode.com/problems/4sum/
//striver sheet
class Solution {
public:
  // Broute force solution 
vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        int n=nums.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
           for(int k=j+1; k<n; k++){
            for(int m=k+1; m<n; m++){
                long long  sum= 1LL*nums[i]+nums[j]+nums[k]+nums[m];
                if(sum==target){
                 vector<int>temp={nums[i],nums[j],nums[k],nums[m]};
                   sort(temp.begin(),temp.end());
                 if(find(ans.begin(),ans.end(),temp)==ans.end()){
                 ans.push_back(temp);   
                 }
                }
            }
           }
            }
        }
        return ans;
    }

        // Better approach using hashset to avoid duplicates
   vector<vector<int>> solve(vector<int>&arr,int n,int &target) {
    
 set<vector<int>>st;
  for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            set<int> hashset;
            for (int k = j + 1; k < n; k++) {
       long long int sum=arr[i]+arr[j]+arr[k];
      long long  fourth=target-sum;
        if(hashset.find(fourth)!=hashset.end()){
            vector<int> temp = {arr[i], arr[j], arr[k], (int)fourth};
                        sort(temp.begin(), temp.end());
                        st.insert(temp); // Deduplicate using set
        }
        hashset.insert(arr[k]);
        }      
  }
  }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
        // Convert the set to a vector of vectors
        vector<vector<int>> ans(st.begin(), st.end());

       



// Optimal approach using two pointers
        sort(nums.begin(), nums.end()); // Sort the input vector
        
        // Iterate over the array
        for (int i = 0; i < n; i++) {
            // Avoid duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            for (int j = i + 1; j < n; j++) {
                // Avoid duplicates for the second element
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                
                int k = j + 1; // Third pointer
                int l = n - 1; // Fourth pointer
                
                while (k < l) {
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    
                    if (sum == target) {
                        // Found a valid quadruplet
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;

                        // Skip duplicates for the third and fourth elements
                        while (k < l && nums[k] == nums[k - 1]) k++;
                        while (k < l && nums[l] == nums[l + 1]) l--;
                    } else if (sum < target) {
                        k++; // Increase the third pointer
                    } else {
                        l--; // Decrease the fourth pointer
                    }
                }
            }
        }

        return ans; // Return the result
    }
};
