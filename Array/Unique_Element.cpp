Input: arr[] = [1, 2, 1, 5, 5]
Output: 2
Explanation: Since 2 occurs once, while other numbers occur twice, 2 is the answer.

//Approach1
int getSingleElement(vector<int> &arr) {
    // Size of the array:
    int n = arr.size();

    //Run a loop for selecting elements:
    for (int i = 0; i < n; i++) {
        int num = arr[i]; // selected element
        int cnt = 0;

        //find the occurrence using linear search:
        for (int j = 0; j < n; j++) {
            if (arr[j] == num)
                cnt++;
        }
        // if the occurrence is 1 return ans:
        if (cnt == 1) return num;
    }
    //This line will never execute
    //if the array contains a single element.
    return -1;
}



//appraoch-2
int findUnique(vector<int> &arr) {
        // code here
        unordered_map<int,int>mp;
        for(int i=0; i<arr.size(); i++){
            mp[arr[i]]++;
        }
        int ans=0;
        
        for(auto it:mp){
            if(it.second==1){
                ans=it.first;
            }
        }
        return ans;
    }


// approach3 - optimal
int findUnique(vector<int> &arr) {
        // code here
       int xori=0;
        for(int i=0; i<arr.size(); i++){
          xori=xori^arr[i];
        }
     
        return xori;
    }
};
