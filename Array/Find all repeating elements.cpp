//striver sheet NQT




//approach time0(n^2) space=0(n)

void solve(vector<int>&arr){
    
    vector<bool>visited(arr.size(),false);
    for(int i=0; i<arr.size(); i++){
        
        if(visited[i]==true){
            continue;
        }
        int count=1;

        for(int j=i+1; j<arr.size(); j++){
            if(arr[i]==arr[j]){
                count++;
                visited[j]=true;
            }
        }

        if(count>1){
            cout<<arr[i]<<" ";
        }
    }
   
}



### DRY run
arr = {2, 3, 1, 9, 3, 1, 3, 9}
visited = [F, F, F, F, F, F, F, F]
🔁 i = 0 → arr[i] = 2
visited[0] = false → proceed
count = 1
j = 1 → 3 ≠ 2
j = 2 → 1 ≠ 2
j = 3 → 9 ≠ 2
j = 4 → 3 ≠ 2
j = 5 → 1 ≠ 2
j = 6 → 3 ≠ 2
j = 7 → 9 ≠ 2

👉 count = 1 → not duplicate → skip

🔁 i = 1 → arr[i] = 3
    
visited[1] = false → proceed
count = 1

j = 2 → 1 ≠ 3
j = 3 → 9 ≠ 3
j = 4 → 3 == 3 → count=2, visited[4]=T
j = 5 → 1 ≠ 3
j = 6 → 3 == 3 → count=3, visited[6]=T
j = 7 → 9 ≠ 3

👉 count = 3 → duplicate
👉 print 3
visited = [F, F, F, F, T, F, T, F]

🔁 i = 2 → arr[i] = 1
visited[2] = false → proceed
count = 1

j = 3 → 9 ≠ 1
j = 4 → skip (already visited)
j = 5 → 1 == 1 → count=2, visited[5]=T
j = 6 → skip
j = 7 → 9 ≠ 1

👉 count = 2 → duplicate
👉 print 1
visited = [F, F, F, F, T, T, T, F]

🔁 i = 3 → arr[i] = 9
    visited[3] = false → proceed
count = 1

🔁 i = 4,5,6,7

👉 All are visited = true → skipped
3 1 9
    
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

