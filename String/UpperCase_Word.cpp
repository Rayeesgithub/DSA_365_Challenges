// striver TCS NQT

#include<bits/stdc++.h>
using namespace std;
void convertUpper(string st){
int n=st.length();
if(st[0]>='a' && st[0]<='z')
st[0]=st[0]-'a'+'A';
 for(int i=1; i<n; i++){
   if(st[i]>='a' && st[i]<='z') {
    if(st[i-1]==' '){
        st[i]=st[i]-'a'+'A';
    }
 }
 }
 for(int i=0; i<n; i++){
    cout<<st[i];
 }
}
int main(){
    string st="i love programming";
    convertUpper(st);
}
