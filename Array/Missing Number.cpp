//https://leetcode.com/problems/missing-number/
//striver sheet
// approach1
 int missingNumber(vector<int>& nums) {
         int ans; int xor1=0; int xor2=0;
       int n=nums.size();
          // Calculate the XOR of all indices from 0 to n
       for(int i=0; i<=n;i++ ){
        xor1=xor1^i;
       }
        // Calculate the XOR of all elements in the array
       for(int i=0; i<n; i++){
        xor2=xor2^nums[i];
    
       } // The missing number is the XOR of xor1 and xor2
       return xor1^xor2;


   //approach-2
    //second approach Time Complexity: O(N) && Space Complexity: O(1) 

    int totalsum= n*(n+1)/2;
    int sum=0;
    for(int i=0; i<n; i++){
        sum=sum+nums[i];
    }
    return totalsum-sum;
    }
