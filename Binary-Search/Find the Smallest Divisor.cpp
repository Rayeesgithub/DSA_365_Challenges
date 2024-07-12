https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

// striver sheet

// broute force
 int smallestDivisor(vector<int>& nums, int threshold) {
       int maxi = *max_element(nums.begin(), nums.end()); // find max Element
      int ans=-1;
        for(int i=1; i<=maxi; i++){
            int sum=0;
            for(int j=0; j<nums.size();j++){
               sum += ceil((double)nums[j] / (double)i);
            }
            if(sum<=threshold){
                ans=i;
                break;
            }
        }
        return ans;
    }
};

// optimal approach
class Solution {
public:
   int Fxn(vector<int>& nums,int mid){
     int sum=0;
    for(int i=0; i<nums.size();i++){
        sum += ceil((double)nums[i] / (double)mid);
    }
    return sum;
   }
    int smallestDivisor(vector<int>& nums, int threshold) {
         if (nums.size()>threshold) return -1;
       int s=1; int e=*max_element(nums.begin(), nums.end()); 
       while(s<=e){
        int mid=s+(e-s)/2;
        if(Fxn(nums,mid)<=threshold){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
       }
       return s;
    }
};
