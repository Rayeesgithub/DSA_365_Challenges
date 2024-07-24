// lovebabbar

#include<iostream>
using namespace std;
  void convertuppercase(string &s){

    for(int i=0; i<s.length(); i++){
        s[i]=s[i]-'a'+'A';
    }
  }
  void convertlowercase(string &s){
     for(int i=0; i<s.length(); i++){
        s[i]=s[i]-'A'+'a';
    }
  }
int main(){
    string str="rayees";
    string str2="RAYEES";
    convertuppercase(str);
    cout<<"After Converting Uppercase:"<<str;
    convertlowercase(str2);
    cout<<endl;
    cout<<"After converting in Lowercase:"<<str2;
}

