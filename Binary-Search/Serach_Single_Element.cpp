https://leetcode.com/problems/single-element-in-a-sorted-array/
//striver sheet

// broute force 1
   for(int i=1; i<n-1; i++){
    if(arr[i-1]!=arr[i]  && arr[i]!=arr[i+1]){
        ans=arr[i];
    }
   }
   return ans;


// broute force2
 int singleNonDuplicate(vector<int>& nums) {
        int xor1=0;
        for(int i=0; i<nums.size(); i++){
        xor1=xor1^nums[i];
        }
        return xor1;
    }
// broute force-2
int singleNonDuplicate(vector<int>& nums) {
        int ans;
        unordered_map<int,int>mp;
        for(int i=0; i<nums.size(); i++){
           mp[nums[i]]++;
        }
        for(auto it:mp){
            if(it.second==1){
                ans=it.first;
            }
        }
        return ans;
    }
// optimal approach
int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size(); // Store the size of the array in n

    // Edge case: if the array has only one element, return that element
    if (n == 1) return nums[0];

    // Edge case: if the first element is unique
    if (nums[0] != nums[1]) return nums[0];

    // Edge case: if the last element is unique
    if (nums[n - 1] != nums[n - 2]) return nums[n - 1];

    int s = 0; 
    int e = n - 1;
 while (s <= e) {
   int mid = s + (e - s) / 2; 

        // Check if the mid element is unique (not equal to its neighbors)
        if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]) {
            return nums[mid]; // Return the unique element
        }

        // Check if we are in the left part (before the unique element)
        // Even index with its next element same or odd index with its previous element same
        if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 != 0 && nums[mid] == nums[mid - 1])) {
            s = mid + 1; // Move to the right part
        }
        else {
            e = mid - 1; // Move to the left part
        }
    }

    return -1; // Return -1 if no unique element is found (this line should never be reached)
}
