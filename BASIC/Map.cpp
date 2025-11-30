✅ What is a Map in C++?
A map is like a dictionary. It stores data in key → value pairs
Example:
| Key | Value   |
| --- | ------- |
| 5   | 3 times |
| 2   | 1 time  |
| 8   | 4 times |


  ✅ Types of Maps in C++
1️⃣ map (ordered map)
Stores elements in sorted order (based on key)
Uses Red-Black Tree internally
Time complexity: O(log n)

2️⃣ unordered_map
Stores elements in random order
Uses Hashing internally
Time complexity: O(1) average


✅ unordered_map Working Concept (Hashing)

unordered_map uses a hash table.
Key → Hash Function → Index → Value stored
Example If key = 5
Hash(5) = bucket 12
→ store value inside bucket 12


✅ Simple Example of unordered_map
unordered_map<int, int> mp;

int arr[] = {5, 6, 5, 7, 6, 5};
int n = 6;

for(int i = 0; i < n; i++) {
    mp[arr[i]]++;   // increase frequency
}

| i | arr[i] | Action  | Map (key → frequency) |
| - | ------ | ------- | --------------------- |
| 0 | 5      | mp[5]++ | {5 → 1}               |
| 1 | 6      | mp[6]++ | {5 → 1, 6 → 1}        |
| 2 | 5      | mp[5]++ | {5 → 2, 6 → 1}        |
| 3 | 7      | mp[7]++ | {5 → 2, 6 → 1, 7 → 1} |
| 4 | 6      | mp[6]++ | {5 → 2, 6 → 2, 7 → 1} |
| 5 | 5      | mp[5]++ | {5 → 3, 6 → 2, 7 → 1} |

  🟩 Final Map Content
5 → 3 times
6 → 2 times
7 → 1 time
Now you can easily print:
for(auto it : mp) {
    cout << it.first << " appears " << it.second << " times\n";
}

🔍 What is it.first?
👉 it.first → key
👉 Example: In pair (5, 3), the key = 5

  🔍 What is it.second?
👉 it.second → value
👉 Example: In pair (5, 3), the value = 3 (frequency)
