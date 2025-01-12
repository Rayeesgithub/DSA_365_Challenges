#include<bits/stdc++.h>
using namespace std;
bool checkAnagram(string st1, string st2){
   if(st1.length()!=st2.length()) return false;
   sort(st1.begin(),st1.end());
   sort(st2.begin(),st2.end());

   for(int i=0; i<st1.length(); i++){
    if(st1[i]!=st2[i]){
        return false;
    }
   }
   return true;
}
int main(){
    string st1; string st2;
    cin>>st1; cout<<endl; cin>>st2; cout<<endl;
    if(checkAnagram(st1,st2)){
        cout<<"Yes This Anagram";
    }
    else{
        cout<<"No this is Not Anagram";
    }

}

// approach2
bool checkAnagram(string st1, string st2){
   if(st1.length()!=st2.length()) return false;
  int freq[26]={0};
  for(int i=0; i<st1.length(); i++){
    freq[st1[i]-'A']++;
  }
  for(int i=0; i<st2.length(); i++){
 freq[st2[i]-'A']--;
  }

  for(int i=0; i<26;i++){
    if(freq[i]!=0){
        return false;
    }

  }
  return true;
}





  bool isAnagram(string s, string t) {
        unordered_map<char,int>mp;
        for(int i=0; i<s.length();i++){
            mp[s[i]]++;
        }
        for(int j=0; j<t.length(); j++){
            mp[t[j]]--;
        }

        for(auto i:mp){
            if(i.second!=0){
                return false;
            }
        }
        return true;
    }
