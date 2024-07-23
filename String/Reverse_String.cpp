// loveBabbar

#include<iostream>
using namespace std;

// approach1
void reverseString(string str){
    for(int i=str.length();i>=0; i--){
        cout<<str[i];
    }
}

//approach2
void reverseString(string &s){
    int left=0; int right=s.length()-1;
    while(left<=right){
       swap(s[left],s[right]);
       left++; right--;
    }
}
int main(){
    string str;
    cout<<"enter the string:";
    cin>>str;
    cout<<endl;
    reverseString(str);
    cout<<str;
}
