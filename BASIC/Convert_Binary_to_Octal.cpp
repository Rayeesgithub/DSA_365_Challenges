#include<bits/stdc++.h>
using namespace std;
string convertInOctal(string &s){
 int n=s.length();
 if(n%3==1){
    s="00"+s;
 }
 else if(n%3==2){
    s="0"+s;
 }

 n=s.length();
 string ans="";
 for(int i=0; i<n; i=i+3){
    int temp=(s[i]-'0')*4+(s[i+1]-'0')*2+(s[i+2]-'0')*1;
    ans+=(temp+'0');
 }
 return ans;
}
int main(){
    string binary;
    cout<<"enter binary Number:";
    cin>>binary;
    string ans=convertInOctal(binary);
    cout<<endl;
    cout<<"Binary Into in Octal:"<<ans;
}
