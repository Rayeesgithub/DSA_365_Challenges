// Broute force

 int maxLength(vector<int>& arr) {
    int maxi = 0; // maximum length
    int n = arr.size();

    for(int i = 0; i < n; i++) {
        int sum = 0; // reset for every i
        for(int j = i; j < n; j++) {
            sum += arr[j]; // accumulate sum from i to j
            if(sum == 0) {
                int len = (j - i + 1);
                maxi = max(maxi, len);
            }
        }
    }
    return maxi;
}

};

//optimal

int maxLength(vector<int>& arr) {
        // code here
        int maxi=0;
        unordered_map<int,int>mp;
        int sum=0;
        for(int i=0; i<arr.size();i++){
           sum=sum+arr[i];
           if(sum==0){
               maxi=i+1;
           }
           else {
               if(mp.find(sum)!=mp.end()){
               maxi=max(maxi,i-mp[sum]);
           }
           else{
               mp[sum]=i;
           }
           }
        }
        return maxi;
    }
};
