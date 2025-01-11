// striver-TCS
#include<bits/stdc++.h>
using namespace std;
bool checkPalindrome(string &s){
bool ans=true;
int i=0; int j=s.length()-1;
while(i<=j){
    if(s[i]!=s[j]){
        ans=false;
    }
    i++; j--;
}
return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
    string s;
    cout<<"enter the Any String :";
    cin>>s;
    if(checkPalindrome(s)){
        cout<<"Palindrome"<<endl;
    }
    else{
        cout<<"this is Not Palindrome"<<endl;
    }
    }
}
