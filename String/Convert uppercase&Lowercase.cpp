input-> rayees/SADAM
output- RAYEES/sadam

#include<iostream>
using namespace std;
void convertuppercase(string &s) {

    for(int i = 0; i < s.length(); i++) {

        // 'a' to 'z' range → ASCII: 97 to 122
        // 'A' to 'Z' range → ASCII: 65 to 90
        // Difference between lowercase & uppercase characters = 32
        // So:
        // s[i] - 'a' gives its position relative to 'a'
        // + 'A' converts that position into uppercase ASCII
       
      s[i] = s[i] - 'a' + 'A';

        // Same work can be done by inbuilt function:
        // s[i] = toupper(s[i]);
    }
}

void convertlowercase(string &s) {
    
    for(int i = 0; i < s.length(); i++) {

        // Reverse of above logic:
        // Convert 'A' (65) → 'a' (97)
        s[i] = s[i] - 'A' + 'a';

        // Or simply:
        // s[i] = tolower(s[i]);
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

