//https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// striver sheet

int main() {
    vector<int> arr = {5, 3, 2, 3, 5, 1, 4, 2};

    // Use map instead of unordered_map
    map<int, int> mp;

    // Count occurrences
    for (int i = 0; i < arr.size(); i++) {
        mp[arr[i]]++;
    }

    // Print unique elements in sorted order
    for (auto it : mp) {
        cout << it.first << " ";
    }

    return 0;
}



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
