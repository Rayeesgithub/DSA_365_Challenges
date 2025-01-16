https://www.geeksforgeeks.org/problems/encrypt-the-string-10337/1


#include<bits/stdc++.h>
using namespace std;
void EncryptString(string st){
    int count=1; string ans="";
    for(int i=0; i<st.length(); i++){
        if(st[i]==st[i+1]){
            count++;
        }
        else{
            ans+=st[i];
            ans+=to_string(count);
            count=1;
        }
    }
    reverse(ans.begin(),ans.end());
    for(int i=0; i<ans.length(); i++){
        cout<<ans[i];
    }
}
int main(){
    int t;
    cin>>t;
   cin.ignore();
    while(t--){
        string st;
        cout<<"enter the string:";
       getline(cin,st);
       EncryptString(st);
       cout<<endl;
    }
}
