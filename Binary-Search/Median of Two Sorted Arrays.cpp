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

// optimal approach
int n1 = nums1.size();
    int n2 = nums2.size();
    
    // Ensure nums1 is the smaller array to minimize the number of operations.
    if (n1 > n2) {
        return findMedianSortedArrays(nums2, nums1);
    }

    int n = n1 + n2;
    int leftmid = (n1 + n2 + 1) / 2;
    int low = 0;
    int high = n1;
    
    while (low <= high) {
        int mid1 = (low + high) / 2;
        int mid2 = leftmid - mid1;

        // Boundaries
        int l1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
        int l2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
        int r1 = (mid1 == n1) ? INT_MAX : nums1[mid1];
        int r2 = (mid2 == n2) ? INT_MAX : nums2[mid2];

        // Check if we have found the correct elements
        if (l1 <= r2 && l2 <= r1) {
            if (n % 2 == 0) {
                // If total length is even
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            } else {
                // If total length is odd
                return max(l1, l2);
            }
        } else if (l1 > r2) {
            // Eliminate the right half of nums1
            high = mid1 - 1;
        } else {
            // Eliminate the left half of nums1
            low = mid1 + 1;
        }
    }
    return 0.0;
    }
