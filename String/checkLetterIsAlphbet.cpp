#include<bits/stdc++.h>
using namespace std;
bool checkLetterIsAlphbet(string s){
  unordered_set<char> letters;

    // Add all letters in the string to the set
    for (char c : s) {
     
        if (isalpha(c)) { // Check if character is an alphabet
            letters.insert(tolower(c)); // Convert to lowercase and insert
        }
    }

    // If the set contains 26 letters, it's a pangram
    return letters.size() == 26;
}
int main(){
  int t;
  cin>>t;
  while(t--){
    string s;
    cin>>s;
    if(checkLetterIsAlphbet(s)){
      cout<<"true"<<endl;
    }
    else{
      cout<<"false"<<endl;
    }
  }
}
