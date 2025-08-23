//https://leetcode.com/problems/longest-consecutive-sequence/
// striver sheet

// broute force


#include <bits/stdc++.h>
using namespace std;

bool linearSearch(vector<int>&a, int num) {
    int n = a.size(); //size of array
    for (int i = 0; i < n; i++) {
        if (a[i] == num)
            return true;
    }
    return false;
}
int longestSuccessiveElements(vector<int>&a) {
    int n = a.size(); //size of array
    int longest = 1;
    //pick a element and search for its
    //consecutive numbers:
    for (int i = 0; i < n; i++) {
        int x = a[i];
        int cnt = 1;
        //search for consecutive numbers
        //using linear search:
        while (linearSearch(a, x + 1) == true) {
            x += 1;
            cnt += 1;
        }

        longest = max(longest, cnt);
    }
    return longest;
}





//optimize solution
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
       int n=nums.size();
       if(n==0) return 0;
        int count=0; int largest=1; int lastSmall=INT_MIN;
        for(int i=0; i<n; i++){
            if(nums[i]-1==lastSmall){
            count++;
            lastSmall=nums[i];
            }
            else if(nums[i]!=lastSmall){
                count=1;
                lastSmall=nums[i];
            }
            largest=max(count,largest);
        }
        return largest;
    }
};
