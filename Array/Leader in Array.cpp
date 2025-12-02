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


// Optimal Apprach

// Optimal Approach
// Time = O(n)  | Space = O(1) extra (ignoring ans array)

void LeaderArr(int arr[], int n, vector<int>& ans) {

    int maxi = arr[n - 1];   // last element is always a leader
    ans.push_back(maxi);     // store the last element

    // Traverse from second last element to start
    for (int i = n - 2; i >= 0; i--) {

        // If the current element is greater than the
        // maximum seen so far on the right → it's a leader
        if (arr[i] > maxi) {
            ans.push_back(arr[i]);
            maxi = arr[i];   // update maximum
        }
    }

    // Note: leaders are stored in reverse order now
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
