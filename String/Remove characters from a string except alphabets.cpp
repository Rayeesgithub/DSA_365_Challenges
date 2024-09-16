//striver sheet TCS
#include<bits/stdc++.h>
using namespace std;
void remove(string &st){
    string ans;
    for(int i=0; i<st.length();i++){
      if(st[i]>='a' && st[i]<='z'){
        ans.push_back(st[i]);
      }
      else{
        continue;
      }
    }
    for(int i=0; i<ans.length(); i++){
        cout<<ans[i];
    }
}
int main(){
    string st="take12% *&u ^$#forward";
    remove(st);
   
}
