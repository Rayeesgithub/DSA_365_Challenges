// love babbar
Input: s = "abba"
Output: true
Explanation: "abba" reads the same forwards and backwards,

 

#include<iostream>
using namespace std;
 bool checkPalindrome(string s){
    int left =0; int right=s.length()-1;
    while(left<=right){
        if(left==right){
            return true;
        }
        else{
            left++; right--;
        }
    }
    return false;
 }
int main(){
    string str="racecar";
    if(checkPalindrome(str)){
        cout<<"this is palindromic string";
    }
    else{
        cout<<"this is Not Palindromic String";
    }
}
