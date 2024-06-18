// GFG->Union of Two Sorted Arrays
// STRIVER SHEET

// 1st approach-> using map fxn   Time Compleixty : O( (m+n)log(m+n) ) && Space Complexity : O(m+n)
vector < int > FindUnion(int arr1[], int arr2[], int n, int m) {
  map < int, int > freq;
  vector < int > Union;
  for (int i = 0; i < n; i++)
    freq[arr1[i]]++;
  for (int i = 0; i < m; i++)
    freq[arr2[i]]++;
  for (auto & it: freq)
    Union.push_back(it.first);
  return Union;
}

// 2nd approach-> using set fxn  Time Compleixty : O( (m+n)log(m+n) ) && Space Complexity : O(m+n)
vector < int > FindUnion(int arr1[], int arr2[], int n, int m) {
  set < int > s;
  vector < int > Union;
  for (int i = 0; i < n; i++)
    s.insert(arr1[i]);
  for (int i = 0; i < m; i++)
    s.insert(arr2[i]);
  for (auto & it: s)
    Union.push_back(it);
  return Union;
}
// Two pointer approach  Time Compleixty : O( (m+n)) && Space Complexity : O(1)
vector<int> findUnion(int arr1[], int arr2[], int n, int m) {
    int i = 0, j = 0;
    vector<int> ans;
    
    // Traverse both arrays
    while (i < n && j < m) {
        // Avoid duplicates in arr1
        if (i > 0 && arr1[i] == arr1[i-1]) {
            i++;
            continue;
        }
        
        // Avoid duplicates in arr2
        if (j > 0 && arr2[j] == arr2[j-1]) {
            j++;
            continue;
        }
        
        if (arr1[i] < arr2[j]) {
            ans.push_back(arr1[i]);
            i++;
        } else if (arr1[i] > arr2[j]) {
            ans.push_back(arr2[j]);
            j++;
        } else {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    
    // If there are remaining elements in arr1
    while (i < n) {
        if (i > 0 && arr1[i] != arr1[i-1]) {
            ans.push_back(arr1[i]);
        }
        i++;
    }
    
    // If there are remaining elements in arr2
    while (j < m) {
        if (j > 0 && arr2[j] != arr2[j-1]) {
            ans.push_back(arr2[j]);
        }
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
