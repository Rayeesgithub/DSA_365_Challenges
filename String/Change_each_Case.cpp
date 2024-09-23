#include<bits/stdc++.h>
using namespace std;
void Countwords(string st){
  for(int i=0; i<st.length();i++){
    if(st[i]>='a'&& st[i]<='z'){
       st[i]=st[i]-'a'+'A';   //st[i] = towupper(str[i]);
    }
    else{
      st[i]=st[i]-'A'+'a';
    }
  }
  for(int i=0; i<st.length();i++){
    cout<<st[i]<<" ";
  }
}
int main(){
 string st="javA";

 Countwords(st);
}
