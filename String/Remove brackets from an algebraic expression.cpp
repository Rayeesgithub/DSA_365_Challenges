// striver sheet TCS

#include<bits/stdc++.h>
using namespace std;
void remove(string &st){
string ans;
for(int i=0; i<st.length();i++){
    if(st[i]=='(' || st[i]==')'){
        continue;
    }
    else{
        ans.push_back(st[i]);
    }
}
for(int i=0; i<ans.length();i++){
    cout<<ans[i];
}
}
int main(){
    string st="a+((b-c)+d)";
    remove(st);
   
}
