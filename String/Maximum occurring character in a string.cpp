Input: str = "apple"
Output: p
Explanation: 
The character 'p' have the maximum occurrence i.e 2.


  void solve(string & str){
  unordered_map<char,int>mp;
  for(int i=0; i<str.size(); i++){
    mp[str[i]]++;
  }

  int maxi=-1;
  char maxfreq;
  for(auto it:mp){
  
    if(it.second>maxi){
        maxi=it.second;
        maxfreq=it.first;
    }
  }

  cout<<"maximum freq:"<<maxfreq;

}
