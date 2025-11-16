Input: S = "Geeks", P = 'e'
Output: 2
Explanation: Last index of 'e' 
is 2.


  //Method1-> iterative appraoch
   int LastIndex(string s, char p) {
        // complete the function here
        int last=0;
        for(int i=s.size()-1; i>=0; i--){
            if(s[i]==p){
               return i;
            }
        }
        return -1;
    }

//Methid2-> Recursive
int findLast(string &s, int i, char p) {
    // Base case: if index becomes negative → character not found
    if (i < 0) return -1;

    // If current character matches, return index
    if (s[i] == p) return i;

    // Otherwise, check previous index
    return findLast(s, i - 1, p);
}

int LastIndex(string s, char p) {
    // Start recursion from the last index
    return findLast(s, s.size() - 1, p);
}

