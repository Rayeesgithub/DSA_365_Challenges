https://leetcode.com/problems/intersection-of-two-arrays/description/

// love babbar


//broute force
 vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
         vector<int> ans;
    
    // Iterate through each element in nums1
    for(int i = 0; i < nums1.size(); i++) {
        // Check if this element is already in the answer vector to avoid duplicates
        if (find(ans.begin(), ans.end(), nums1[i]) != ans.end()) {
            continue;
        }
        
        // Iterate through each element in nums2
        for(int j = 0; j < nums2.size(); j++) {
            // If we find a match, add it to the answer vector and break out of the inner loop
            if(nums1[i] == nums2[j]) {
                ans.push_back(nums1[i]);
                break;  // No need to check further for this element
            }
        }
    }
    
    return ans;
}

// optimal approach'
    }
