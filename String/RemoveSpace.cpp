#include<bits/stdc++.h>
using namespace std;
string RemoveSpace(string &st){
    string ans;
    for(int i=0; i<st.length(); i++){
        if(st[i]==' '){
            continue;
        }
        else{
            ans+=st[i];
        }
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        string st;
        cout<<"enter the string:";
       getline(cin,st);
        string ans=RemoveSpace(st);
        cout<<"After remove space :"<<ans<<endl;
    }
}
