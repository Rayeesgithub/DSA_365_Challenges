https://www.interviewbit.com/problems/subarray-with-given-xor/
// striver sheet

// Broute force
#include <bits/stdc++.h>
using namespace std;
int subarraysWithXorK(vector<int> a, int K) {
  int n=a.size(); int count=0;
for(int i=0; i<n;i++){
for(intj=i; j<n; j++){
int xor=0;
for(int k=i; k<n;k++){
xor=xor^a[k];
}
if(xor==K)
  count++;
}
}
  return count;
}

// better  approach
int count=0;
for(int i=0;  i<n; i++){
int xor=0;
for(intj=i; j<n; j++){
  xor=xor^a[j];
}
if(xor==k) count++;
}
return count;
}

// optimal approach
int subarraysWithXorK(vector<int> a, int k) {
    int n = a.size(); 
    int xr = 0; // Variable to store the prefix XOR.
    map<int, int> mpp; // Declaring the map to store the prefix XOR and its frequency.
    mpp[xr]++; // Setting the initial value of 0 in the map.
    int cnt = 0; // Counter to keep track of the number of subarrays with XOR equal to k.

    // Loop through each element of the array.
    for (int i = 0; i < n; i++) {
        // Calculate the prefix XOR up to index i.
        xr = xr ^ a[i];

        // By the formula: x = xr ^ k.
        // We find the number of occurrences of xr ^ k in the map.
        int x = xr ^ k;

        // Add the occurrences of xr ^ k to the count.
        cnt += mpp[x];

        // Insert the prefix XOR up to index i into the map.
        mpp[xr]++;
    }
    
    // Return the total count of subarrays with XOR equal to k.
    return cnt;
}
