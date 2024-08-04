// self


approach1
void removeDuplicate(vector<int>&arr){
    set<int>st;
   for(int i=0; i<arr.size();i++){
    st.insert(arr[i]);
   }
   for(auto it:st){
    cout<<it<<" ";
   }
}
int main(){
    vector<int>arr={1, 3, 2, 2, 4, 3, 3, 1};
    removeDuplicate(arr);
}



// approach2
void removeDuplicate(vector<int>&arr){
   unordered_map<int,bool>mp;
   vector<int> uniqueNums;
   for(int i=0; i<arr.size();i++){
    if(mp.find(arr[i])==mp.end()){
       mp[arr[i]]=true;
       uniqueNums.push_back(arr[i]);
    }
   }
   for(int i=0; i<uniqueNums.size();i++){
    cout<<uniqueNums[i]<<" ";
   }
}
int main(){
    vector<int>arr={1, 3, 2, 2, 4, 3, 3, 1};
    removeDuplicate(arr);
}
