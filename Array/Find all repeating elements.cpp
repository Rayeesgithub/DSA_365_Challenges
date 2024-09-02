//striver sheet NQT

#include<bits/stdc++.h>
using namespace std;

int main() {
   int n=8;
   int arr[n]={1,1,2,3,4,4,5,2};
    map<int,int>mp;
    for(int i=0; i<n; i++){
      mp[arr[i]]++;
    }

for(auto it:mp){
   if(it.second>1){
    cout<<it.first<<" ";
   }
}

}

//second approach
#include<bits/stdc++.h>
using namespace std;

void findRepeatingElements(vector<int>& arr) {
    sort(arr.begin(),arr.end());
    
    cout<<"The repeating elements are: ";
    for(int i=0;i<arr.size()-1;i++) 
        if(arr[i] == arr[i+1]) cout<<arr[i]<<" ";
}

int main() {
    vector<int> arr = {1,1,2,3,4,4,5,2};
    findRepeatingElements(arr);
    return 0;
}
