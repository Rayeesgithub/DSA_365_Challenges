//https://geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1


Input: arr = [10, 22, 12, 3, 0, 6]  
Output: 22 12 6  
Explanation: 6 is a leader because there are no elements after it.  
12 is greater than all the elements to its right (3, 0, 6), and 22 is greater than 12, 3, 0, 6, making them leaders as well.


// approach1 Time = O(n^2) && space = O(1)

vector<int> leaders(vector<int>& arr) {
    vector<int> ans;      
    int n = arr.size();

    // A leader is the element which is greater than or equal to
    // all elements to its right.
    
    for (int i = 0; i < n; i++) {
        bool isLeader = true;   // assume arr[i] is leader
        
        // Check all elements to the right of arr[i]
        for (int j = i + 1; j < n; j++) {

            // If any element to the right is greater,
            // then arr[i] is NOT a leader
            if (arr[i] < arr[j]) {
                isLeader = false;
                break;           // stop checking further
            }
        }

        // If element remained leader → push to answer
        if (isLeader) {
            ans.push_back(arr[i]);
        }
    }

    return ans;
}



// Optimal Approach
// PATTERN-> Traversal / Searching
// Time = O(n)  | Space = O(1) extra (ignoring ans array)

vector<int> findLeaders(vector<int>& arr) {
    int n = arr.size();
    vector<int> leaders;
    
    // 1. Base Case: The rightmost element is always a leader
    int current_max = arr[n - 1];
    leaders.push_back(current_max);
    
    // 2. Scan the array backwards from right to left
    for (int i = n - 2; i >= 0; i--) {
        // 3. Core Logic: If current element is strictly greater 
        // than the max seen to its right, it's a leader!
        if (arr[i] >= current_max) {
            current_max = arr[i]; // Update the running maximum
            leaders.push_back(current_max);
        }
    }
    
    // 4. Since we collected leaders from back to front, 
    // reverse the result to match original array ordering
    reverse(leaders.begin(), leaders.end());
    
    return leaders;
}
int main(){
  int n=6;
  int arr[n]={10, 22, 12, 3, 0, 6};
  vector<int>ans;
  LeaderArr(arr,n,ans);
  for(int i=ans.size()-1; i>=0; i--){
   cout<<ans[i]<<" ";
  }
}
