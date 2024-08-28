//striver sheet

vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
     map<int,int>mp;
     for(int i=0; i<N; i++){
         mp[Arr[i]]++;
     }
     vector<long long int>ans;
     for(auto it:mp){
         if(it.second&1){
             ans.push_back(it.first);
         }
     }
    reverse(ans.begin(),ans.end());
     return ans;
    }
