Input: 20 15 26 2 98 6
Output: 4 3 5 1 6 2
Explanation: When sorted,the array is 2,6,15,20,26,98. So the rank of 2 is 1,rank of 6 is 2,rank of 15 is 3 and so.

void solve(vector<int>&arr){
    int n=arr.size();
   for(int i=0; i<n; i++){
    int count=1;
    for(int j=0; j<n; j++){
      if(arr[i]>arr[j]){
        count++;
      }
    }
     cout<<count<<" ";
   }

    
   
}
