//https://leetcode.com/problems/median-of-two-sorted-arrays/description/
// striver

// broute force 
 double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0; int j=0;  int ele=-1;
        int cnt=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
               
                i++;
            }
            else{
                ans.push_back(nums2[j]);
                j++;
            }
        }
        while(i<nums1.size()){
            ans.push_back(nums1[i++]);
        }
        while(j<nums2.size()){
            ans.push_back(nums2[j++]);
        }
      int n = ans.size();

    // Calculate the median
    if (n % 2 == 0) {
        // If even, median is the average of the two middle elements
        return (ans[n / 2 - 1] + ans[n / 2]) / 2.0;
    } else {
        // If odd, median is the middle element
        return ans[n / 2];
    }
   
    }
