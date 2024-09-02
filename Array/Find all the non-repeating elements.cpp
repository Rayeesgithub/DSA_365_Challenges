//striver sheet NQT
#include<bits/stdc++.h>
using namespace std;

int main() {
   int n=6;
   int arr[n]={1,2,-1,1,3,1};
    unordered_map<int,int>mp;
    for(int i=0; i<n; i++){
      mp[arr[i]]++;
    }

for(auto it:mp){
   if(it.second==1){
    cout<<it.first<<" ";
   }
}

}

// optimal Approach
#include<bits/stdc++.h>
using namespace std;

void findNonRepeatingElement(vector<int>& nums) {
    sort(nums.begin(),nums.end());//sorting array
    
    //handling first element of the array.
    if(nums[0] != nums[1]) cout<<nums[0]<<" ";
    
    for(int i=1;i<nums.size()-1;i++) 
       if(nums[i-1] != nums[i] && nums[i] != nums[i+1]) cout<<nums[i]<<" ";
       
    //handling last element of the array
    if(nums[nums.size()-2] != nums[nums.size()-1]) cout<<nums[nums.size()-1];
}

int main() {
    vector<int> nums = {1,2,-1,1,3,1};
    cout<<"Non-repeating numbers are: "<<endl;
    findNonRepeatingElement(nums);
    
    return 0;
}

