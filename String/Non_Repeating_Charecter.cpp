//1st approach

void solve(string & str){
     vector<bool>visited(str.size(),false);
   for(int i=0; i<str.size(); i++){
    int count=1;
    if(visited[i]==true){
        continue;
    }
    for(int j=i+1; j<str.size(); j++){

     if(str[i]==str[j]){
        count++;
        visited[j]=true;
     }
    }

    if(count==1){
        cout<<str[i]<<" ";
    }

   }

}



// 2nd approach
char nonrepeatingCharacter(string S)
    {
       //Your code here
      char ans;
  map<char,int>mp; int n=S.length();
    for(int i=0; i<n; i++){
      mp[S[i]]++;
    }
    for(auto it:mp){
        if(it.second==1){
          return it.first;
        }
    }
     return '$';  
    }
