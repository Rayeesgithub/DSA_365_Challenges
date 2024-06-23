//https://geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1
// striver sheet


class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(int n, int arr[]) {
//         // Broute force
//         vector<int> ans;
//          for (int i = 0; i < n; i++) {
//           bool leader = true;

//       //Checking whether arr[i] is greater than all 
//       //the elements in its right side
//     for (int j = i + 1; j < n; j++)
//       if (arr[j] > arr[i]) {
          
//         // If any element found is greater than current leader
//         // curr element is not the leader.
//         leader = false;
//         break;
//       }
//   // Push all the leaders in ans array.
//     if (leader)
//     ans.push_back(arr[i]);

//   }
  
//   return ans;
    
       // optimal approach
       
       vector<int>ans;
      int maxi=INT_MIN;
      for(int i=n-1; i>=0; i--){
          if(arr[i]>=maxi){
              maxi=arr[i];
              ans.push_back(arr[i]);
          }
         
      } 
      reverse(ans.begin(),ans.end());
      return ans;
