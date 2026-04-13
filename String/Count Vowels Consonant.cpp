//striver sheet

#include<bits/stdc++.h>
using namespace std;
void CountTerms(string st,int &vow,int &consotant,int &space){
   int n=st.length();
   for(int i=0; i<n; i++){
    st[i]=tolower(st[i]);
   }
   for(int i=0; i<n; i++){
    if(st[i]=='a' || st[i]=='e' ||st[i]=='i' || st[i]=='o'|| st[i]=='u'){
        vow++;
    }
    else if(st[i]>='a' && st[i]<='z'){
        consotant++;
    }
    else if(st[i]==' '){
      space++;
    }
   }
}
int main(){
    string st="India won the cricket match";
   
    int vow=0; int consotant=0; int space=0;
    CountTerms(st,vow,consotant,space);
    cout<<"Number of Vowels is:"<<vow<<endl;
    cout<<"Number of Consonant is:"<<consotant<<endl;
    cout<<"Number of Number of Space is:"<<space<<endl;
    return 0;
}
