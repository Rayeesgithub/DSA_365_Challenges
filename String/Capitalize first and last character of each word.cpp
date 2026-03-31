
//approach1
void solve(string & str){
   
    str[0]=toupper(str[0]);
    str[str.size()-1]=toupper(str[str.size()-1]);

    for(int i=1; i<str.size()-1; i++){
        if(str[i+1]==' ' || str[i-1]==' '){
            str[i]=toupper(str[i]);
        }
    }
cout<<"after revers: "<<str;

}





//Striver TCS NQT

approach-2
 #include<bits/stdc++.h>
using namespace std;

void solve(string &str){

    int n = str.size();

    for(int i = 0; i < n; i++){

        // check if current char is first of word
        if(i == 0 || str[i-1] == ' '){
            str[i] = toupper(str[i]);
        }

        // check if current char is last of word
        if(i == n-1 || str[i+1] == ' '){
            str[i] = toupper(str[i]);
        }
    }

    cout << str;
}



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
