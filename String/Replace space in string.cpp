// love babbar

i/p→ My name is Babbar
olp=>  My@name@is@Babbar
#include<iostream>
using namespace std;
string Replace(string s){
    for(int i=0; i<s.length();i++){
        if(s[i]==' '){
           s[i]='@';
        }
    }
    return s;
}
int main(){
    string str="My Name is Rayees Alam";
    cout<<"Before Replace string"<<str<<endl;
    string ans=Replace(str);
    cout<<"after replace string:"<<ans<<endl;
}
