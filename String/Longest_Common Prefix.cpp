//https://leetcode.com/problems/longest-common-prefix/description/
//striver sheet

#include<bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string>&arr){
  sort(arr.begin(),arr.end());
  string first=arr[0];
  string last=arr[arr.size()-1];
  string ans="";
  for(int i=0; i<min(first.size(),last.size());i++){
    if(first[i]==last[i]){
      ans.push_back(first[i]);
    }
    else{
      break;
    }
  }
  return ans;
}
int main(){
  int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> arr(n); // Initialize the vector after reading n
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        string ans = longestCommonPrefix(arr);
        cout << "Longest Common Prefix: " << ans << endl;
    }
  
}
