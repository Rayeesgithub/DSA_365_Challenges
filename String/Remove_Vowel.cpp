//Striver TCS
#include<bits/stdc++.h>
using namespace std;
void RemoveVowel(string &st){
    for(int i=0; i<st.length();i++){
        st[i]=tolower(st[i]);
    }
    string ans;
    for(int i=0; i<st.length(); i++){
        if(st[i]=='a' || st[i]=='e' || st[i]=='i' || st[i]=='o' || st[i]=='u'){
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
   string st="I am very happy today";
   RemoveVowel(st);
}
