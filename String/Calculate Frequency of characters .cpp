//striver TCS NQT

#include<bits/stdc++.h>
using namespace std;
void countFreq(string st){
    int n=st.length();
    map<char,int>mp;
    for(int i=0; i<n; i++){
        mp[st[i]]++;
    }
    for(auto it:mp){
        cout<<it.first<<"->"<<it.second<<" ";
    }
}
int main(){
    string st="takeuforward";
    countFreq(st);
}


// aprroach2
using namespace std;
void Printfrequency(string str)
{
  sort(str.begin(), str.end());
  char ch = str[0];
  int count = 1;
  for (int i = 1; i < str.length(); i++)
  {
    if (str[i] == ch)
      count++;
    else
    {
      cout << ch << count << " ";
      count = 1;
      ch = str[i];
    }
  }
  cout << ch << count << " ";
}

