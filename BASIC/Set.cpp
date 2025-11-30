✅ What is a set in C++? (Super Simple)

A set is a container that stores unique elements only.
✔ No duplicates
✔ Automatically sorted (in set)
✔ Fast searching

✅ Types of Sets
1️⃣ set (ordered set)
Stores elements in sorted order
Backed by Red-Black Tree
Searching/Insertion: O(log n)

2️⃣ unordered_set
Stores elements in random order
Uses Hashing
Searching/Insertion: O(1) average

Example-
set<int> s;

s.insert(5);
s.insert(1);
s.insert(3);
s.insert(5); // duplicate
output-> 1 3 5

In map, each element is:
(key → value)
  it.first, it.second

Here we only have
it.first
  
  
  set<int> s;

int arr[] = {5, 3, 5, 7, 3, 9};
int n = 6;

for(int i=0; i<n; i++){
    s.insert(arr[i]);
}

// printing
for(auto it : s){
    cout << it << " ";
}

| Step | Arr[i] | Insert?                    | Set Content     |
| ---- | ------ | -------------------------- | --------------- |
| 1    | 5      | Insert                     | {5}             |
| 2    | 3      | Insert                     | {3, 5} (sorted) |
| 3    | 5      | Already exists → No insert | {3, 5}          |
| 4    | 7      | Insert                     | {3, 5, 7}       |
| 5    | 3      | Already exists             | {3, 5, 7}       |
| 6    | 9      | Insert                     | {3, 5, 7, 9}    |

 
  ✅ 1. multiset (allows duplicates)
👉 What is multiset?
multiset is like set but duplicates are allowed.

✔ Key points:
Stores elements in sorted order
Allows multiple identical values
2 3 5 5

✅ 2. Set Operations
⭐ A) Find element → find()
Use find() to check if an element exists.
if(s.find(5) != s.end())
    cout << "Found";
If value exists → returns iterator
If not → returns s.end()


  ⭐ B) Erase element → erase()
Remove elements using erase()
s.erase(5);

⭐ C) Union of two sets (Combine unique values only)
set<int> s1 = {1, 2, 3};
set<int> s2 = {3, 4, 5};
set<int> uni;

for(int x : s1) uni.insert(x);
for(int x : s2) uni.insert(x);
uni = {1, 2, 3, 4, 5}

⭐ D) Intersection

(Common values only)
set<int> inter;

for(int x : s1){
    if(s2.find(x) != s2.end())  
        inter.insert(x);
}
inter = {3}


⭐ E) Difference

(Values in s1 that are NOT in s2)

set<int> diff;

for(int x : s1){
    if(s2.find(x) == s2.end())
        diff.insert(x);
}


s1 = {1,2,3}, s2={3,4} → difference = {1,2}
