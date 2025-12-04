//striver sheet NQT




//approach time0(n^2) space=0(n)
#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> arr = {1,1,2,3,4,4,5,2};
    vector<int> ans;  // to store repeating elements

    for (int i = 0; i < arr.size(); i++) {

        for (int j = i + 1; j < arr.size(); j++) {

            // Check if element repeats
            if (arr[i] == arr[j]) {

                // Check if we already added this repeating element
                if (find(ans.begin(), ans.end(), arr[i]) == ans.end()) {
                    ans.push_back(arr[i]);
                }
            }
        }
    }

    // Print the repeating elements
    for (auto it : ans) {
        cout << it << " ";
    }

    return 0;
}




// 2nd approach time=0(n) space=0(n)

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

