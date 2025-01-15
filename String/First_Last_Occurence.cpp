
#include <bits/stdc++.h>
using namespace std;
void findFirst_LastOcuu(string& st,string &sub){
int firstIndex=st.find(sub);
 int LastIndex=st.rfind(sub);

cout<<"firstOcuurnce is:"<<firstIndex<<" ";
cout<<"secondOcuurnce is:"<<LastIndex;
}
int main() {
	// your code goes here
	int t;
	cin>>t;
    cin.ignore(); // Clear the newline character from the input buffer
	while(t--){
	    string st,sub;
		cout<<"enter the String:";
		  getline(cin, st);
        cout << "Enter the pattern to find: ";
       getline(cin, sub);
		findFirst_LastOcuu(st,sub);
		cout<<endl;
	}
	
	return 0;
}
