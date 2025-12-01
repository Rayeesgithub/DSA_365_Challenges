// GFG->Union of Two Sorted Arrays
// STRIVER SHEET

Input:
n = 10,m = 7.
arr1[] = {1,2,3,4,5,6,7,8,9,10}
arr2[] = {2,3,4,4,5,11,12}
Output: {1,2,3,4,5,6,7,8,9,10,11,12}
Explanation: 
Common Elements in arr1 and arr2  are:  2,3,4,5
Distnict Elements in arr1 are : 1,6,7,8,9,10
Distnict Elemennts in arr2 are : 11,12
Union of arr1 and arr2 is {1,2,3,4,5,6,7,8,9,10,11,12} 

  

// 1st approach-> using map fxn 
  Time Compleixty : O( (m+n)log(m+n) )(map insertion takes logN)  && Space Complexity : O(m+n)

  
vector<int> FindUnion(int arr1[], int arr2[], int n, int m) {

    // Map will store each number as key (unique) and count as value
    map<int, int> freq;

    // Insert all elements of arr1 into map
    for (int i = 0; i < n; i++)
        freq[arr1[i]]++;  // O(log n)

    // Insert all elements of arr2 into map
    for (int i = 0; i < m; i++)
        freq[arr2[i]]++;  // O(log m)

    vector<int> Union;

    // Now map contains each element only once (sorted order)
    for (auto &it : freq)
        Union.push_back(it.first);

    return Union;
}
;
}



// 2nd approach-> using set fxn
Time Compleixty : O( (m+n)log(m+n) ) && Space Complexity : O(m+n)

vector<int> FindUnion(int arr1[], int arr2[], int n, int m) {

    // Set automatically keeps ONLY unique values in sorted order
    set<int> s;

    // Insert arr1 elements
    for (int i = 0; i < n; i++)
        s.insert(arr1[i]);  // O(log n)

    // Insert arr2 elements
    for (int i = 0; i < m; i++)
        s.insert(arr2[i]);  // O(log m)

    vector<int> Union;

    // Extract elements from set into vector
    for (auto &it : s)
        Union.push_back(it);

    return Union;
}





// Two pointer approach  Time Compleixty : O( (m+n)) && Space Complexity : O(1)
vector<int> findUnion(int arr1[], int arr2[], int n, int m) {

    int i = 0, j = 0;                // Two pointers
    vector<int> ans;

    // Traverse both arrays until one finishes
    while (i < n && j < m) {

        // Skip duplicate elements in arr1
        if (i > 0 && arr1[i] == arr1[i - 1]) {
            i++;
            continue;
        }

        // Skip duplicate elements in arr2
        if (j > 0 && arr2[j] == arr2[j - 1]) {
            j++;
            continue;
        }

        // If arr1 element is smaller → push it
        if (arr1[i] < arr2[j]) {
            ans.push_back(arr1[i]);
            i++;
        }

        // If arr2 element is smaller → push it
        else if (arr1[i] > arr2[j]) {
            ans.push_back(arr2[j]);
            j++;
        }

        // Both equal → push only once
        else {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    // Add remaining elements of arr1
    while (i < n) {
        if (i == 0 || arr1[i] != arr1[i - 1])   // ensure no duplicate
            ans.push_back(arr1[i]);
        i++;
    }

    // Add remaining elements of arr2
    while (j < m) {
        if (j == 0 || arr2[j] != arr2[j - 1])   // ensure no duplicate
            ans.push_back(arr2[j]);
        j++;
    }

    return ans;
}

int main() {
  int n = 10, m = 7;
  int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int arr2[] = {2, 3, 4, 4, 5, 11, 12};
  vector < int > Union = FindUnion(arr1, arr2, n, m);
  cout << "Union of arr1 and arr2 is " << endl;
  for (auto & val: Union)
    cout << val << " ";
  return 0;
}
