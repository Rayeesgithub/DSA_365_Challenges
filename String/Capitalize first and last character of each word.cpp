//Striver TCS NQT

#include<bits/stdc++.h>
using namespace std;
void convertUpper(string st){
int n=st.length();
if(st[0]>='a' && st[0]<='z')
st[0]=st[0]-'a'+'A';
if(st[n-1]>='a' && st[n-1]<='z')
st[n-1]=st[n-1]-'a'+'A';
 for(int i=1; i<n; i++){
   if(st[i]>='a' && st[i]<='z') {
    if(st[i-1]==' ' || st[i+1]==' '){
        st[i]=st[i]-'a'+'A';
    }
 }
 }
 for(int i=0; i<n; i++){
    cout<<st[i];
 }
}
int main(){
    string st="take u forward is awesome";
    convertUpper(st);
}
