You are given a string s, and your task is to reverse the string.

Examples:

Input: s = "Geeks"
Output: "skeeG"
Input: s = "for"
Output: "rof"



    

// Approach 1: Printing string in reverse
// ----------------------------------------
void reverseString_print(string str) {

    // Start from last index → str.length() - 1
    for(int i = str.length() - 1; i >= 0; i--) {

        // print characters from end to start
        cout << str[i];
    }

    // This function only PRINTS
    // It does NOT modify original string
}



// ----------------------------------------
// Approach 2: Two–pointer method
// ----------------------------------------
void reverseString_twoPointer(string &s) {

    int left = 0;
    int right = s.length() - 1;

    // Keep swapping until both meet
    while(left <= right) {

        // swap characters at left and right
        swap(s[left], s[right]);

        left++;
        right--;
    }
}



// ----------------------------------------
// Approach 3: Using STL reverse()
// ----------------------------------------
void reverseString_STL(string &s) {

    // reverse() directly reverses the string
    reverse(s.begin(), s.end());
}

int main(){
    string str;
    cout<<"enter the string:";
    cin>>str;
    cout<<endl;
    reverseString(str);
    cout<<str;
}
