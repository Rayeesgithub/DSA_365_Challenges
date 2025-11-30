✅ 1. What is Hashing? (Super Simple Explanation)
Hashing = A fast way to store and find data using a special key called a hash value.

Think of it like:
📫 You have 1000 letters.
Instead of searching letter by letter,
you directly jump to the exact locker number (hash value)

You store the data in that index. When searching, the same hash function gives the same index
So search becomes O(1) (constant time)

✅ 2. Why do we use hashing?
Because hashing gives:
Fast Insert → O(1)
Fast Search → O(1)
Fast Delete → O(1)

✅ 3. Real Life Example
Imagine you have 10 buckets numbered:
0,1,2,3,4,5,6,7,8,9
You want to store roll numbers: 19, 22, 35
Use a hash function: index = roll % 10
  | Roll | Hash        | Stored at index |
| ---- | ----------- | --------------- |
| 19   | 19 % 10 = 9 | bucket 9        |
| 22   | 22 % 10 = 2 | bucket 2        |
| 35   | 35 % 10 = 5 | bucket 5        |


✅ 5. Collision (Important)

Collision happens when:
Two values give the same hash index.
hash(17) = 7
hash(27) = 7



  int arr[] = {2, 5, 2, 7, 5, 2};
    int n = 6;

    int hash[13] = {0};

    // Build frequency hash
    for (int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }


⭐ 1. Search a number= if (hash[5] > 0) → found
⭐ 2. Check if a number is unique
hash[7] = 1 → unique ✓
hash[5] = 2 → not unique ✗
⭐ 3. Print all unique numbers
for (int i = 0; i < 13; i++) {
    if (hash[arr[i]] == 1) {
            cout << arr[i] << " ";
        }
} 
o/p-> 7
⭐ 4. Count frequency
 // Count frequency
    for (int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }

    // Print frequency
    for (int i = 0; i < 13; i++) {
        if (hash[i] > 0) {
            cout << i << " -> " << hash[i] << endl;
        }
    }


⭐ Character Hashing
✅ Code if the string contains only lowercase:
 int hash[26] = {0};
    for (int i = 0; i < s.size(); i++) {
        hash[s[i] - 'a']++;
    }

⭐ Why s[i] - 'a' ?
To convert a character into array index.
| Character | ASCII | ASCII of 'a' | Subtraction | Index |
| --------- | ----- | ------------ | ----------- | ----- |
| 'a'       | 97    | 97           | 97-97       | 0     |
| 'b'       | 98    | 97           | 98-97       | 1     |
| 'c'       | 99    | 97           | 99-97       | 2     |

s = "abbca"
Output
| Character  | Frequency |
| ---------- | --------- |
| a          | 2         |
| b          | 2         |
| c          | 1         |
| all others | 0         |

✅ Code if the string contains both uppercase and lowercase:
  int hash[256] = {0};
    for (int i = 0; i < s.size(); i++) {
        hash[s[i]]++;
    }


This hashing works for:
lowercase: a, b, c …
uppercase: A, B, C …
digits: 0–9
symbols: @, $, %, etc.
spaces, tabs, punctuation
Everything is covered.

| Character   | ASCII | Used as index |
| ----------- | ----- | ------------- |
| 'A'         | 65    | hash[65]      |
| 'a'         | 97    | hash[97]      |
| '0'         | 48    | hash[48]      |
| '@'         | 64    | hash[64]      |
| space `' '` | 32    | hash[32]      |
