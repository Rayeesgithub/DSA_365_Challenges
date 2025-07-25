//https://leetcode.com/problems/move-zeroes/
// striver sheet


Input: 1 ,0 ,2 ,3 ,0 ,4 ,0 ,1
Output: 1 ,2 ,3 ,4 ,1 ,0 ,0 ,0
Explanation: All the zeros are moved to the end and non-negative integers are moved to front by maintaining order



#include <iostream>
#include <vector>
using namespace std;
// approacch 1 T.Complexity=0(n) && space complexity=0(n)
void moveZeroes(vector<int>& nums) {
    int n = nums.size();  // Get the size of the input vector
 // Create a temporary vector to store non-zero elements
    vector<int> temp;
  // Add non-zero elements to the temporary vector
    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            temp.push_back(nums[i]);
        }
    }
 int size=temp.size();
    
    // Copy elements from the temporary vector back to the original vector
    for (int i = 0; i < size; i++) {
        nums[i] = temp[i];
    }

    for (int i = size; i < n; i++) {
       
            nums[i]=0; }
  


// broute force
 void moveZeroes(vector<int>& nums) {
      int n=nums.size();
      vector<int>ans; vector<int>ans2;
      for(int i=0; i<n;i++){
        if(nums[i]!=0){
          ans.push_back(nums[i]);
        }
        else{
            ans2.push_back(nums[i]);
        }
      }  
       
       for(int i=0; i<ans.size();i++){
       nums[i]=ans[i];
       
      }  
      int m=ans.size(); 
      for(int i=0; i<ans2.size();i++){
       nums[i+m]=ans2[i];
       
      }  
     
    }
};




// otimize approazed
    void MoveZero(int arr[],int &n){
   int left=0;
   for(int right=0; right<n; right++){
     if(arr[right]!=0){
        swap(arr[left],arr[right]);
        left++;
     }
   }

   for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
   }



        
    // second approach-> using two pointer T.Complexity=0(n) && space complexity=0(1)
int j=-1;
for(int i=0; i<n; i++){
if(nums[i]==0) {
    j=i;
    break;
}
}
for(int i=j+1; i<n; i++){
    if(nums[i]!=nums[j]){
        swap(nums[j],nums[i]);
        j++;
    }
}
}
int main() {
    vector<int> nums = { 9 ,0 ,12 ,8 ,0 ,4 ,0 ,5,0};

    moveZeroes(nums);

    // Print the modified vector
    for (int i : nums) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
