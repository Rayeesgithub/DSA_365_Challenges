//striver sheet

// broute force
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=10;int m=7;
    int arr1[n]={1,2,3,4,5,6,7,8,9,10};
     int arr2[m]={2,3,4,4,5,11,12};
  vector<int>temp;
   for(int i=0; i<n; i++){
    temp.push_back(arr1[i]);
   }
     for(int i=0; i<m; i++){
    temp.push_back(arr2[i]);
   }
   set<int>st;
   for(int i=0; i<temp.size();i++){
    st.insert(temp[i]);
   }
   for(auto it:st){
    cout<<it<<" ";
   }
}


//optimal approach
#include<bits/stdc++.h>
using namespace std;
void uninon(int arr1[], int arr2[],int n,int m){
   vector<int>unione;  int i=0; int j=0;
 while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            if (unione.empty() || unione.back() != arr1[i]) {
                unione.push_back(arr1[i]);
            }
            i++;
        } else if (arr1[i] > arr2[j]) {
            if (unione.empty() || unione.back() != arr2[j]) {
                unione.push_back(arr2[j]);
            }
            j++;
        } else {  // arr1[i] == arr2[j], add any one and move both
            if (unione.empty() || unione.back() != arr1[i]) {
                unione.push_back(arr1[i]);
            }
            i++;
            j++;
        }
    }

 
  while (i < n) {
        if (unione.back() != arr1[i]) {
            unione.push_back(arr1[i]);
        }
        i++;
    }

    // Add remaining elements of arr2, if any
    while (j < m) {
        if (unione.back() != arr2[j]) {
            unione.push_back(arr2[j]);
        }
        j++;
    }

    // Print the union of both arrays
    for (auto val : unione) {
        cout << val << " ";
    }
}
int main(){
    int n=10;int m=7;
    int arr1[n]={1,2,3,4,5,6,7,8,9,10};
     int arr2[m]={2,3,4,4,5,11,12};
 
  uninon(arr1,arr2,n,m);
 
}
