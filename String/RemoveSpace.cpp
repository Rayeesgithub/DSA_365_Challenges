#include<bits/stdc++.h>
using namespace std;
void removeSpace(string &st){
    string ans;
    for(int i=0; i<st.length();i++){
       if(st[i]==' '){
        continue;
       }
       else{
        ans.push_back(st[i]);
       }
    }
    for(int i=0; i<ans.length(); i++){
        cout<<ans[i];
    }
}
int main(){
    string st="How are you doing";
    removeSpace(st);
   
}
