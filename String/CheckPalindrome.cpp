// striver-TCS
#include<bits/stdc++.h>
using namespace std;
bool checkPalindrome(string st){
    int n=st.size();
    int i=0; int j=n-1;
    while(i<=j){
        if(st[i]!=st[j]){
           return false;
        }
        i++; j--;
    }
    return true;
}
int main(){
   string st;
   cin>>st;
    if(checkPalindrome(st)){
        cout<<"This is palindrome";
    }
    else{
        cout<<"This is Not Palindrome";
    }
}
