//https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// striver sheet





//print
#include<bits/stdc++.h>
using namespace std;
int main() {
   int n=7;
   int arr[n]={1,1,2,2,2,3,3};
   set<int>st;
   for(int i=0; i<n; i++){
    st.insert(arr[i]);
   }
   for(auto it:st){
    cout<<it<<" ";
   }
}

// second approach
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n = 7;
    int arr[n] = {1, 1, 2, 2, 2, 3, 3};
    
    int i = 0;
    for (int j = 1; j < n; j++) {
        if (arr[i] != arr[j]) {
            i++; // Move the pointer to the next position
            arr[i] = arr[j]; // Assign the non-duplicate element to the correct position
        }
    }
    // Print the unique elements
    for (int k = 0; k <= i; k++) {
        cout << arr[k] << " ";
    }
    
    return 0;
}


// Time complexity: O(n*log(n))+O(n) && Space Complexity: O(n) 
int removeDuplicates(int arr[], int n) {
// sets only store unique elements.
    set<int> set;
 // Iterate through the array and insert each element into the set and Duplicate elements will be ignored by the set.
    for (int i = 0; i < n; i++) {
        set.insert(arr[i]);
    }
// Get the size of the set, which represents the number of unique elements
    int k = set.size();
  int j = 0; // Index to store elements back into the array

    // Iterate through the set and store each unique element back into the array
    for (int x : set) {
        arr[j++] = x;
    }  
  return k;  // Return the number of unique elements
}

//optimal approach->using two pointer      Time Complexity: O(N) && Space Complexity: O(1)
int removeDuplicates(int arr[], int n) {
    // Initialize a variable i to track the position of the last unique element
    int i = 0;
for (int j = 1; j < n; j++) {
        // If the current element is different from the last unique element
        if (arr[i] != arr[j]) {
            // Move the position of the last unique element forward
            i++;
            // Update the array to include the new unique element
            arr[i] = arr[j];
        }
    }

    // Return the count of unique elements
    // i is the index of the last unique element, so the count is i + 1
    return i + 1;
}

int main() {
    int arr[] = {12, 35, 1, 10, 34, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int k = removeDuplicates(arr, n);

    cout << "The array after removing duplicates: ";
    for (int i = 0; i < k; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Number of unique elements: " << k << endl;

    return 0;
}
