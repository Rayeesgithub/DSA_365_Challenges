// love Babbar

#include<iostream>
using namespace std;
string RemoveSpace(string s){
     string str;
    for(int i=0; i<s.length();i++){
       
        if(s[i]!=' '){
          str+=s[i];
        }
    }
    return str;
}
int main(){
    string str="My Name is Rayees Alam";
    cout<<"Before Replace string:"<<str<<endl;
    string ans=RemoveSpace(str);
    cout<<"after replace string:"<<ans<<endl;
}
